#include<iostream>
using namespace std;
int n,m,a[500010],b[500010],cnt=0,ans[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				b[i]=0;
			}
			for(int j=i;j<=n;j++){
				int x=0;
				for(int k=1;k<=cnt;k++){
					if(b[k]==a[j]){
						cnt=k;
						x=1;
					} 
				}
				if(x==0){
					b[++cnt]=a[j];
				}
			}
			for(int k=1;k<=cnt;k++){
				ans[b[k]]++;
			}
			cnt=0;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	return 0;
}
