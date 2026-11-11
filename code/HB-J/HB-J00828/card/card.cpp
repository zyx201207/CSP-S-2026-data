#include <bits/stdc++.h>
using namespace std;
int a[500005],ju[500005],b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x=0,y=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		memset(ju,0,sizeof(ju));
		for(int j=i;j<=n;j++){
			if(j==i){
				ju[j]=a[j];
				continue;
			}
			bool flag=0,k;
			for(int w=1;w<j;w++){
				if(ju[w]==a[j]){
					flag=1;
					k=w;
					break;
				}
			}
			if(flag==1){
				for(int w=k+1;w<=j;w++){
					ju[w]=-1;
				}
			}
			else{
				ju[j]=a[j];
			}
		}
		//for(int j=i;j<=n;j++){cout<<ju[j]<<" ";}cout<<endl;
		for(int j=i;j<=n;j++){
			if(ju[j]==1){
				x++;
			}
			if(ju[j]==2){
				y++;
			}
		}
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}
