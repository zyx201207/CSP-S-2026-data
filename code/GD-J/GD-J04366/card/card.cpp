#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,m,a[N],ans[N],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int num=1;num<=n;num++){
		int cnt=0;
		for(int i=num;i<=n;i++){
			int flag=0;
			for(int j=1;j<=cnt;j++){
				if(b[j]==a[i]){
					for(int k=j;k<=cnt;k++){
						b[k]=-1;
					}
					cnt=j;
					b[cnt]=a[i];
					flag=1;
					break;
				}
			}
			if(flag==0)b[++cnt]=a[i];
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=cnt;j++){
				if(b[j]==i){
					ans[i]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
