#include<bits/stdc++.h>
using namespace std;
int n,m,b[500005],sum[500005];
long long a[500005];
bool f[500005];
struct node{
	int xx,yy;
}ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j]=a[j];
		}
		for(int j=1;j<=m;j++){
			ans[j].xx=0;
			ans[j].yy=0;
		}
		for(int j=i;j<=n;j++){
			ans[b[j]].xx++;
			if(ans[b[j]].xx>1){
				for(int k=ans[b[j]].yy;k<j;k++){
					//f[k]=0;
					b[k]=0;
				}
				ans[b[j]].yy=j;
			}//else{
//				f[j]=1;
//			}
			ans[b[j]].yy=j;
		}
		for(int j=i;j<=n;j++){
			sum[b[j]]++;
			cout<<b[j]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
