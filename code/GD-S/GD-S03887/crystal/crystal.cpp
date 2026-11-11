#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+10;
int n,m;
int a[MAXN];
bool cmp(int a,int b){
	return a<b;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a,a+n,cmp);
	vector<int>v;
	v.push_back(a[0]);
	int k=0,ANS=1;
	int CNT=1;
	int j=0;
	for(int i=1;i<n;i++){
		k=k+(a[i]-v[v.size()-1])*(CNT);
		v.push_back(a[i]);
		CNT++;
		while(k>m){
			k-=(v[v.size()-1]-v[j]);
			CNT--;
			j++;
		}
		ANS=max(ANS,CNT);
	}
	cout<<ANS;
	return 0;
}

