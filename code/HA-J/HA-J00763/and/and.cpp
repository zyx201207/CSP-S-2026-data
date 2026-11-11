#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005][35],ans=0,os[500005][50],re[50];
void ejz(long long p,long long bh){
	long long ind=30;
	while(p){
		b[bh][ind]=p%2;
		p/=2;
		ind--;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ejz(a[i],i);
	}
	bool f=1;
	for(int k=1;k<=500005;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(op[k][i-1]<j){
					os[k][i]=j;
				}
			}
		}
	}
	for(int k=1;k<=500005;k++){
		for(int i=1;i<=30){
			f=f&&b[os[k][i]][i];
			re[i]=re[i]&&f;
		}
	}
	long long ds=1;
	for(int i=30;i>0;i--){
		ans+=re[i]*ds;
		ds*=2;
	}
	cout<<ans;
	return 0;
}
