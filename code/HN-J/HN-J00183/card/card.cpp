#include<bits/stdc++.h>
using namespace std;
int a[500010];
int vis[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			vis[j]=0;
			if(a[i]==a[j]){
				vis[i]=0;
				
			}
			
		}
	}
	cout<<n<<m;
	return 0;
}
