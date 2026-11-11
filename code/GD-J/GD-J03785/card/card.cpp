#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],ans[300005],b[500005],n,m;
bool c[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int t=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<t;j++){
			if(b[j]==a[i]){
				for(int l=j;l<t;l++) b[l]=0;
				t=j-1;
				j=t;
			}
		}
		b[t]=a[i]; t++;
		for(int j=1;j<t;j++){
			int q=b[j];
			c[q]=1;
		}
		for(int i=1;i<=m;i++){
			if(c[i]==1)ans[i]++;
			c[i]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
