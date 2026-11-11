#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll m,n,maxn;
int a[500005];
//map<ll,ll>mp;
bool cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		//mp[x]++;
		a[i]=x;
	}
	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++){//
//		cout<<a[i]<<' ';//
//	}cout<<"\n\n";//
	for(int i=1;i<n;i++){
		ll tmp=m,cnt=1;
		for(int j=i+1;j<=n&&tmp>0;j++){
			if(a[i]-a[j]<=tmp){
				cnt++;
				tmp-=(a[i]-a[j]);
			}
			//cout<<cnt<<" "<<tmp<<'\n';//
			//else break;
		}
		//cout<<'\n';//
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
}
