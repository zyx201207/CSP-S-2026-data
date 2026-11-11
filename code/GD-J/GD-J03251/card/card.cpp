#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300100],b[300100],c[300100];
long long q[300100],k=1;
void v(int I){
	for(int i=I;i<=n;i++){
		if(b[a[i]]==0){
			q[k]=a[i],k++;
			b[a[i]]=1;
		}else{
			long long t=k-1;
			while(q[t]!=a[i]){
				b[q[t]]=0,q[t]=0,t--;
			}
			k=t+1;
		}
	}
	for(int i=1;i<=k;i++){
		if(q[i]!=0){
			c[q[i]]++;
			q[i]=0;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		v(i);
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
