#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
bool b[300005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				for(int h=i;h<=j;h++){
					if(a[j]==a[h]&&c[h]){
						for(int y=h;y<j;y++){
							b[a[y]]=0;
							c[y]=0;
						}
						break;
					}
				}
			}
			b[a[j]]=1;
			c[j]=1;
		}
		for(int h=1;h<=m;h++){
			if(b[h]){
				ans[h]++;
			}
			b[h]=0;	
		}
		for(int j=1;j<=n;j++){
			c[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
