#include<bits/stdc++.h>
#define int long long
const int N=2e5+10;
using namespace std;
int n,m,a[N],b[N],c[N],ma=-1;
void f(int k,int q){
	if(k>m){
		int t=b[1];
		for(int j=2;j<=m;j++)t&=b[j];
		ma=max(ma,t);
		return;
	}else{
		for(int i=q+1;i<=n;i++){
			b[k]=a[i];
			f(k+1,i);
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	f(1,0);
	cout<<ma;
	return 0;
} 
