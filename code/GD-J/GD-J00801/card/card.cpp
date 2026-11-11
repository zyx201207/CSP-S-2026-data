#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],s[300010],n1,b[500010],f[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[a[j]]!=0){
				for(int w=f[a[j]]+1;w<=n1;w++)f[b[w]]=0;
				n1=f[a[j]];
			}
			else n1++,f[a[j]]=n1,b[n1]=a[j];
		}
		n1=0;
		for(int j=1;j<=m;j++){
			if(f[j]!=0)s[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<" ";
	return 0;
}
