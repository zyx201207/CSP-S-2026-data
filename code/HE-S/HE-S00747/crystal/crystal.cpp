#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m,cc,bj,o,d,s;

bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<long long> a;
	for(int i=0;i<n;i++){
		cin>>o;
		a.push_back(o);
		cc+=a[i];
	} 
	bj=cc/n+1;
	sort(a.begin() ,a.end());
	int t=a.size()-1,cnt=0;
	for(int i=0;i<t;i++){
		cnt+=a[t]-a[i];
	}
	if(m>=cnt){
		cout<<n;
		return 0;
	}
	for(long long i=a.size()-1;i>=0;i--){
		if(a[i]>bj){
			a.pop_back();
		}
	}
	sort(a.begin() ,a.end() ,cmp);
	d=a[0];
	for(long long i=1;i<a.size();i++){
		if(s+d-a[i]<=m){
			s+=d-a[i];
			ans++;
		}
		else{
			break;
		}
	}
	cout<<ans;
	return 0;
} 
