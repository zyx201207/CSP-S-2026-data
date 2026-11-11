#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],di[300001],now,ans[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int time=1;time<=n;time++){
		now=1;
		for(int i=1;i<=m;i++){
			di[i]=0;
		}
		for(int i=n-time+1;i<=n;i++){
			if(!di[a[i]]){
				di[a[i]]=now;
				now++;
			}
			else{
				for(int j=1;j<=m;j++){
					if(di[j]>di[a[i]]){
						di[j]=0;
						now--;
					}
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(di[i]){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
	}
	return 0;
}
