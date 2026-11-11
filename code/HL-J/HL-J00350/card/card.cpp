#include <iostream>
using namespace std;
int a[200005];
bool vis[20005]={0}; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int t=n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>a[i];
	} 
	for(int i=1;i<=n;i++){
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				vis[i]=1;
				t-=1;
			}
		}
	}
	cout<<t;
	return 0;
}
