#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in ","r",stdin);
    freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	long long d[100010],n[2000100],ans[100010];
	for(int i=1;i<=t;i++){
		long long p;
		cin>>p>>d[i];
		for(long long j=1;j<=p;j++){
		    cin>>n[j];
		}
		long long b[2000100],u=0,v=0;
		for(long long j=1;j<p;j++){
		    b[j]=b[j+1]-b[j];
		    if(b[j]>d[i])
		        u++;
	    }
	    for(long long j=4;j<p;j++){
		    if(b[j]-b[j-4]<=d[i])
		        v++;
	    }
	    if(p-3-v-u>=0)ans[i]=p-3-v-u;
	    else ans[i]=0;  
	}
	for(int i=1;i<=t;i++)
	    cout<<ans[i]<<'\n';
	return 0;
}
