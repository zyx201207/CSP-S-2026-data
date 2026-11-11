#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,sum[2000005],a[2000005],ans,ma[2000005],w[2000005];
void dfs(long long cnt,long long num){
	if(cnt>0){
		if(!ma[num]){
			ma[num]=cnt;
			w[num]++;
		}
		else if(cnt==ma[num]){
			w[num]++;
		    if(w[num]==2)ans++;
		    if(w[num]==3)ans--;
		}
		
	}
	for(int i=num+sum[num];i>num;i--){
		dfs(cnt+1,i);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		memset(sum,0,sizeof(sum));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		} 
		for(int i=1;i<=n;i++){
		    for(int j=i+1;j<=n;j++){
		    	if(a[j]-a[i]<=d){
		    		sum[i]++;
				}
				else break; 
			}
		}
		for(int i=1;i<=n;i++){
			dfs(0,i);
			for(int i=1;i<=n;i++){
				w[i]=0;ma[i]=0;
			}
		}
		cout<<ans<<endl;
		
	}

}
