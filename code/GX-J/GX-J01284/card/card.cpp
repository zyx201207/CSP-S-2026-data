#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	vector<int> b(n+1);
	vector<int> c(m+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			for(int x=i;x<j;x++){
				if(b[j]==a[x]){
					for(int y=x;y<j;y++){
						b[y]=0;
					}
				}
			}
		}
		for(int z=i;z<=n;z++){
			c[b[z]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
