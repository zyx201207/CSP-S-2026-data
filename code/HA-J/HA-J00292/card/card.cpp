#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100005],b[100005],d[300005]={};
long long c[100005],e[100005],f[100005]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	int h=b[n],v=0;
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			c[i]=a[i];
			if(d[a[i]]==1){
				for(int j=k;j<=n;1){
					e[j]=c[j];
					v++;
					if(e[j]==a[j]){
						for(int j=1;j<=v;j++){
							c[j]=e[j];
						}
						break;
					}
				}
			}
			d[a[i]]=1;
		}
		for(int i=k;i<=n;i++){
			f[c[i]]+=1;
		}
	}
	for(int i=1;i<=h;i++){
		cout<<f[i]<<" ";
	}
	return 0;
}
