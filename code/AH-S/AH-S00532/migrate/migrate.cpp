#include<bits/stdc++.h>
using namespace std;
int c,t,n,p,q,f=0,ans=0,v[2000001],minn=2e6;
long long d,a[2000001];
void dfs(int e,int cnt){
	if(e==q){
		if(cnt<minn){
		    minn=cnt;	
		    f=1;
		}else if(cnt==minn){
		    f++;
		}
		return;
	}
    for(int i=p+1;i<=q;i++){
	    if(v[i]==0&&abs(a[e]-a[i])<=d){
		    v[i]=1;
		    dfs(i,cnt+1);	
		    v[i]=0;
		}else if(abs(a[e]-a[i])>d)break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
	    cin>>n>>d;
	    for(int i=1;i<=n;i++)cin>>a[i];	
	    for(int i=1;i<=n;i++){
		    for(int j=i+3;j<=n;j++){
				if(abs(a[j]-a[i])<=d)continue;
				p=i,q=j;
			    dfs(i,0);
			    if(f==2)ans++;
			    f=0;	
			    minn=2e6;
			}	
		}
		cout<<ans<<endl;
		ans=0;
	}
    return 0;	
}
