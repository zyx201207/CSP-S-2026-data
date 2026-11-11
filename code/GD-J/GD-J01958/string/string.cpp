#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
ll n,a[N],ans,jw;
char c[N];
bool v=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]!=c[i-1])v=0;
		else a[i-1]+=a[i],i--,n--;
	}
	if(v){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n/2;i++){
		if(c[i]==c[n-i+1]){
			if(a[i]!=a[n-i+1]) ans+=abs(a[i]-a[n-i+1]);
			jw=abs(a[i]-a[n-i+1]);
			if(a[i]<a[n-i+1]){
	    		int j=i;
	    		while(jw){
	    			if(jw>a[j]) c[j]=c[i];
	    			else a[j]-=jw;
	    			jw=max(0*1ll,jw-a[j]);
	    			j++;
				}
			}
			if(a[i]>a[n-i+1]){
	    		int j=n-i+1;
	    		while(jw){
	    			if(jw>a[j]) c[j]=c[n-i+1];
	    			else a[j]-=jw;
	    			jw=max(0*1ll,jw-a[j]);
	    			j--;
				}
			}
	    }
	    else{
	    	ans+=max(a[i],a[n-i+1]);
	    	jw=max(a[i],a[n-i+1]);
	    	if(a[i]<a[n-i+1]){
	    		int j=i;
	    		while(jw){
	    			if(jw>a[j]) c[j]=c[i];
	    			else a[j]-=jw;
	    			jw=max(0*1ll,jw-a[j]);
	    			j++;
				}
			}
			if(a[i]>a[n-i+1]){
	    		int j=n-i+1;
	    		while(jw){
	    			if(jw>a[j]) c[j]=c[n-i+1];
	    			else a[j]-=jw;
	    			jw=max(0*1ll,jw-a[j]);
	    			j--;
				}
			}
		}
	}
	cout<<ans;	
	return 0;
} 
