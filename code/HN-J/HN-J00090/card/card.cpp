#include<bits/stdc++.h>
using namespace std;
int a[500010],mp[300010],b[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    memset(b,0,sizeof(b));
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(mp[a[j]]){
				for(int k=1;k<=m;k++){
					if(mp[k]<mp[a[j]]){
						mp[k]=0;
					}
				}
				mp[a[j]]=j;
			}
			else{
				mp[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			b[j]+=(mp[j]!=0);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
}
