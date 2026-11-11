#include<iostream>
using namespace std;
int n,m,a[500010],ans[300010],a1[500010];
struct{
	int x;int y;
}b[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a1[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[j]=a1[j];
		}
		for(int j=i;j<=n;j++){
			if(b[a[j]].x==0){
				b[a[j]].x=1;
				b[a[j]].y=j;
			}
			else {
				for(int z=j;z>b[a[j]].y;z--){
					b[a[z]].x=0;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(b[a[j]].x==1) ans[a[j]]++;
		} 
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
	}
	return 0;
}
