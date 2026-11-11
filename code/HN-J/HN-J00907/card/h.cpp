#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],qian[600005],ans[300005];
long long u=300000;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		int now=1;
		for(int j=i;j<=n;j++){
			
			if(qian[a[j]]==0){
				qian[a[j]]=u-now;
				now++;
				
			}
			else{
				long long maxn=0;
				for(int h=1;h<=m;h++){
					if(qian[h]>=qian[a[j]]){
						qian[h]=0;
					}
					else{
						qian[h]+=qian[a[j]];
						
					}
				}
				
				qian[a[j]]=u-now;
			}
			
		}
		for(int j=1;j<=m;j++){
			if(qian[j]>0){
				ans[j]++;
			}
		} 
		for(int j=1;j<=m;j++){
			qian[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
} 
