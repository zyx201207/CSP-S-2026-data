#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],ans[M],cnt,b[N];
bool f=false;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]>a[i+1]){
			f=true;
			break;
		}
	}
	if(f==false){
		for(int k=0;k<n;k++){
			cnt=0;
			for(int i=k+1;i<=n;i++)b[++cnt]=a[i];
			for(int i=1;i<=cnt;i++){
				if(b[i]==b[i-1]){
					b[i-1]=-1;
				}
			}
			for(int i=1;i<=cnt;i++){
				if(b[i]!=-1){
					ans[b[i]]++;
				}
			}
			for(int i=1;i<=cnt;i++)b[i]=0;
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	}
	for(int k=0;k<n;k++){
		cnt=0;
		for(int i=k+1;i<=n;i++)b[++cnt]=a[i];
		for(int i=1;i<=cnt;i++){
			for(int j=i-1;j>=1;j--){
				if(b[i]==b[j]){
					for(int k=j;k<i;k++)b[k]=-1;
				}
			}
		}
		for(int i=1;i<=cnt;i++){
			if(b[i]!=-1){
				ans[b[i]]++;
			}
		}
		for(int i=1;i<=cnt;i++)b[i]=0;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
