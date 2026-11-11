#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[500005],ma=-1,b[300005];
bool fl[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int pos=0;
		for(int j=i;j<=n;j++){
			pos++;
			if(fl[a[j]]==0){
				ma=max(ma,a[j]);
				fl[j]=1;
			}else if(fl[a[j]]){
				bool boom=0;
				for(int k=i;k<j;k++){
					if(c[k]==a[j])boom=1;
					if(boom){
						c[k]=0;
						pos--;
					}
				}
			}c[pos]=a[j];
		}for(int i=1;i<=ma;i++)fl[i]=0;
		for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)if(c[j]==i)b[i]++;
		for(int i=1;i<=pos;i++)c[i]=0;
	}for(int i=1;i<=m;i++)cout<<b[i]<<' ';
}
