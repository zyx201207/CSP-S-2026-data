#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],pre[500005];
bool cmp(int a,int b){
	return a<b;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,k,tong=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		pre[i]=abs(a[i+1]-a[i]);
	}
	for(int i=0;i<n;i++){
		int t=k;
		k-=pre[i]*i+1;
		if(k==0){
			cout<<i+2;
			break;
		}
		else if(k<0){
			if(t-pre[i]*(i-1)-k==pre[i])cout<<t-pre[i]*(i-1);
			else cout<<i+1;
			break;
		}
	}
	if(k>0){
		cout<<n;
	}
	return 0;
}
