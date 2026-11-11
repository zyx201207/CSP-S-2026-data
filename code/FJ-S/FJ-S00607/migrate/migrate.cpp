#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
long long n,d,x[2000005],c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int iq=0;iq<t;iq++){
    	int ans=0;
    	cin>>n>>d;
	    for(int i=1;i<=n;i++){
		    cin>>x[i];
	    }
	    for(int i=1;i<n;i++){
	    	long long k=i;
	    	vector<int> v;
			v.push_back(k);
	    	while(k<n && x[k]+d>x[k+1]){
	    		k=upper_bound(x+1,x+1+n,x[k]+d)-x-1;
	    		v.push_back(k);
			}
			int kq=v.size();
			int dp=0;
			v.push_back(v[kq-1]);
	    	for(int j=1;j<kq;j++){
	    		if(dp==0){
	    			int ncao=upper_bound(x+1,x+1+n,x[v[j]-2]+d)-x-1;
	    			int gay=upper_bound(x+1,x+1+n,x[v[j]-1]+d)-x-1;
	    			int ui=gay-max(v[j],ncao);
	    			ans+=ui;
	    			if(gay==v[j+1]){
	    				dp=1;
					}
					continue;
				}
				else{
					int gay=upper_bound(x+1,x+1+n,x[v[j]-1]+d)-x-1;
	    			ans+=(v[j+1]-gay);
				}
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
