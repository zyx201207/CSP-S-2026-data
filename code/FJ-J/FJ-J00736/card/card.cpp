#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s=1,b[500005],f[300005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(s!=n){
		for(int i=s;i<=n;i++){
			if(f[a[i]])for(int j=f[a[i]]+1;j<=i;j++)b[j]=0;
			else{
				b[i]=a[i];
				f[a[i]]=i;
			}
		}for(int i=s;i<=n;i++){
			if(b[i])c[b[i]]++;
			b[i]=0;
			f[i]=0;
		}
	}for(int i=1;i<=m;i++)cout<<c[i]<<" ";
}
