#include<iostream> 
#include<string> 
#include<cstdio> 
#include<algorithm> 
#include<vector>
#define int long long
using namespace std;

int a[500005];
int t[500005],cnt[500005],ans[500005],c1[500005],c2[500005];

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=5000){
		for(int i=1;i<=n;i++){
			int p=0;
			for(int j=1;j<=m;j++)cnt[j]=0,t[j]=0;
			
			for(int j=i;j<=n;j++){
				if(cnt[a[j]]==0){
					p++;
					cnt[a[j]]=p;
					t[p]=a[j];
				}else{
					
					int st=cnt[a[j]]+1;
					for(int k=st;k<=p;k++){
						cnt[t[k]]=0;
					}
					p=st-1;
				}
				
			}
			for(int i=1;i<=p;i++){
				ans[t[i]]++;
			}
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";		
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			if(a[i]==a[n]){
				if(a[i]==1)ans[1]++;
				else ans[2]++;
			}else{
				ans[1]++,ans[2]++;
			}
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";		
		return 0;
	}

	return 0;
}


