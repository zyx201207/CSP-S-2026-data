#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
unsigned long long d,ans=0;
unsigned long long x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t>0){
		cin>>n;
		cin>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(x[n]-x[1]<=d){
			cout<<0<<endl;
		}else{
			unsigned long long cnt=x[2]-x[1];
		    bool ok=1;
		    for(int i=2;i<=n;i++){
			    if(cnt!=x[i]-x[i-1]){
				    ok=0;
			    }
		    }
		    if(ok){
		        if(d<cnt){
			        cout<<0<<endl;
		        }else{
			        cout<<(x[n]-x[1])/d<<endl;
		        }			
	        }else{
	        	int w=0;
	    	    for(int i=1;i<=n;i++){
	    	        if(x[i]-x[i]<=d&&x[n]-x[i]<=d){
	    	        	w=i;
					}
				}
				for(int i=1;i<=w;i++){
					for(int j=w+1;j<=n;j++){
						if(x[j]-x[i]>d&&((x[j-1]-x[i]<d&&x[j]-x[i+1]>d)||(x[j-1]-x[i]>d&&x[j]-x[i+1]<d))){
							ans++;
						}
					}
				}
				cout<<ans;
		    }		
		}
	}
	t--;
}
