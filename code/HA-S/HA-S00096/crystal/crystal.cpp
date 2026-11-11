#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long> a;
map<long long,int> cnt;
bool cmp(long long a,long long b){
	return a<b;
}
__int128 ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	a.resize(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	sort(a.begin(),a.end(),cmp);
	a.erase(unique(a.begin(),a.end()),a.end());
	for(int i=0;i<n;i++){
		//从i开始，往前走，一直走到m没了为止
		__int128 ansi=cnt[a[i]];
		__int128 mi=m;
		int j=i-1;
		while(mi!=0){
			if(j<0) break;
			__int128 caj=cnt[a[j]];
			__int128 aj=a[j];
			if(mi>=(a[i]-caj*aj)){
				ansi+=cnt[a[j]];
				mi=mi-caj*aj;
			}
			else{
				ansi+=(mi/(a[i]-a[j]));
				mi=0;
			}
			j--;
		}
		ans=max(ans,ansi);
	}
	string s="";
	while(ans!=0){
		s.push_back((ans%10)+'0');
//		cout<<(int)((ans%10))<<endl;
		ans/=10;
//		cout<<s<<endl;
	}
	cout<<s<<"\n";
	return 0;
}
/*
5 5
1 2 4 8 9
*/
