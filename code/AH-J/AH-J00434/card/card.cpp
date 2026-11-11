#include <iostream>
using namespace std;
int a[500005],b[500005],ans[500005],n,m;
bool flag(int x,int y){
	for(int i=x;i<=n;i++){
		if(y==b[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(!flag(i,a[j])){
				for(int x=i;x<=n;x++){
					b[x]=0;
				}
			}
			a[j]=b[j];
		}
		for(int j=i;j<=n;j++){
			if(b[j]!=0){
				ans[b[j]]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
    return 0;
}
