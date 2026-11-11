#include<iostream>
using namespace std;
int a[500010];
int b[300010];
int c[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt=1;
		for(int j=1;j<=n;j++){
			c[a[j]]=0;
		}
		for(int j=i;j<=n;j++){
			if(c[a[j]]==0){
				c[a[j]]=cnt;
				cnt++;
			}
			else{
				cnt=c[a[j]]+1;
				for(int k=j-1;k>=i+cnt-1;k--){
					c[a[k]]=0;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(c[j]) b[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
