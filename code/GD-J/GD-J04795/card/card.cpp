#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=500050;
int a[N],b[N],ans[N]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		memset(b,0,sizeof(b));
		int l=0;
		for(int i=k;i<=n;i++){
			for(int j=l;j>=1;j--){
				if(b[j]==a[i]){
					l=j-1;
					break;
				}
			}
			b[++l]=a[i];
		}
		for(int i=1;i<=l;i++){
			ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
