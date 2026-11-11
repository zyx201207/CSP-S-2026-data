#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
map <int,int> ways;
int mx=-0x3f3f3f3f,mxways;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		ways[a[i]]++;
	}
	sort(a+1,a+1+n,cmp);
	for(auto v:ways){
		int mm=m,cnt=0;
		int tod=v.first;
//		cout<<tod<<" ";
//		cout<<endl;
//		cout<<"tod="<<tod<<" ";
		for(int i=1;i<=n;i++){
			if(a[i]<=tod&&tod-a[i]<=mm){
				mm-=(tod-a[i]);
				cnt++;
//				cout<<i<<" ";
			}
		}
		mx=max(mx,cnt);
		mxways=tod;
	}
	cout<<mx;
	return 0;
}
