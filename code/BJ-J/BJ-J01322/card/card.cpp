#include<bits/stdc++.h>
using namespace std;
int n,m,f[300005],fx[300005],a[500005],ain[500005],top=0,sum[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ain[i];
	}
	for(int T=1;T<=n;T++){
		top=0;
		for(int i=1;i<=m;i++) f[i]=0,fx[i]=0;
		for(int i=1;i<=n;i++) a[i]=0;
		for(int i=T;i<=n;i++){
			if(f[ain[i]]==0){
				fx[ain[i]]=++top;
				a[top]=ain[i];
				f[ain[i]]=1;
			}
			else{
				for(int j=fx[ain[i]]+1;j<=top;j++){
					f[a[j]]=0;
					a[j]=0;
				}
				top=fx[ain[i]];
			}
		}
		for(int i=1;i<=m;i++){
			sum[a[i]]++;
			//cout<<a[i]<<" ";
		}
		//cout<<"\n";
	}
	//cout<<"\n";
	//cout<<m<<"\n";
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
