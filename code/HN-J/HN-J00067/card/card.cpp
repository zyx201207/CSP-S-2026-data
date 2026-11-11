#include<bits/stdc++.h>
using namespace std;
int n ,m;
int a[500005];
int cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(a[1]!=0){
		int b[500005];		
		int f[300005];
		for(int i=1;i<=n;i ++){
			if(cnt[a[i]]==0){
				b[i]=a[i];
				f[a[i]]=1;
			}
			else{
				int x;
				for(int j=1;j<=i;j ++){
					if(b[j]==a[i]){
						x=j;
						break;
					}
				}
				for(int k=x;k<=i-1;k++){
					b[k]=0;
					f[a[i]]= 0;
				}
				b[i]=a[i];
				f[a[i]]=1;			
			}
		}
		for(int l=1;l<=m;l++){
			if(f[l]==1){
				cnt[l]++;
			}
		}
		a[1]=0;
		for(int i=1;i<=n;i++)a[i]=a[i+1];
		a[n] = 0;
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	return 0;
} 
