#include<bits/stdc++.h>
using namespace std;
int n,av,pos=1;
int a[500005];
long long m,sum,res,d;
bool flag;
int mx=-1e9,vmx=-1e9,vmn=1e9; 
bool cmp(int x,int y){
	return x-n/2+1<y-n/2+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		vmx=max(vmx,a[i]);
		vmn=min(vmn,a[i]);
		if(a[i]!=i)
			flag=1;
		d=abs(a[i+1]-a[i]);
	}
	if(!flag){
		for(int i=1;i<=n;i++){
			if(i*(i-1)/2>m){
				cout<<i-1;
				break;
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(i*(i-1)/2*d>m){
			cout<<i-1;
			break;
		}
	}
	return 0;
}

