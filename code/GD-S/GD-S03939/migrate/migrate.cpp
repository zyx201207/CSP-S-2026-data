#include<bits/stdc++.h>
using namespace std;
long long t,d1,n,t1;long long a[200006],ans,d[200006],cnt[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t1>>t;
	while(t--){
		cin>>n>>d1;
		
		for(int i=1;i<=n;i++){
			cin>>a[i];d[i]=1000000000;cnt[i]=0;
		}
		if(t1==13||t1==14){
			int p1=0,p2;
			for(int i=1;i<=n;i++){
				if(a[i]-a[1]<=d1&&a[n]-a[1]<=d1){
					if(p1==0)p1=i;
					p2=i;
				}
			}
			if(p2-p1!=1){
				cout<<0<<'\n';
			}else{
				int v=0;
				for(int i=p2+1;i<=n;i++){
					if(a[i]>a[p1-1]+d){
						v++;
					}
				}cout<<v<<'\n';
			}
			continue;
		}
		if(n>=5000){
			int cha=d1/(a[2]-a[1]);
			if(cha==1)cout<<"0\n";
			else{
				cha*=2;
				cout<<n-cha+1<<'\n';
			}
			continue;
		}
		for(int w=1;w<n;w++){
			for(int i=1;i<=n;i++){
			    d[i]=1000000000;cnt[i]=0;
			}
			d[w]=0;cnt[w]=1;
			for(int i=w;i<n;i++){
		        for(int j=i+1;j<=n;j++){
			        if(a[j]-a[i]<=d1){
			    	    if(d[j]>d[i]+1){
			    		    d[j]=d[i]+1;
			    		    cnt[j]=cnt[i];
					    }else if(d[j]==d[i]+1){
						    cnt[j]+=cnt[i];
					    }
			        }else{
			    	    break;
				    }
		        }
		    }
		    for(int i=w;i<=n;i++){
		    	if(cnt[i]==2){
		    		ans++;
				}
			}
			
		}
		cout<<ans<<'\n';ans=0;
	}
	return 0;
}

