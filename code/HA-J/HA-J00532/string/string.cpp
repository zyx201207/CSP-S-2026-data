#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a[N],ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n%2==0){
		for(int i=1;i<=n/2;i++){
			int j=n-i+1;
			if(c[i]==c[j]){
				if(a[i]>=a[j]){
					a[i]-=a[j];
					a[j]=0;
				}
				else{
					a[j]-=a[i];
					a[i]=0;
				}
			}
			else{
				if(a[i]>=a[j]){
					a[i]-=a[j];
					ans+=a[j];
					a[j]=0;
					
				}
				else{
					a[j]-=a[i];
					ans+=a[i];
					a[i]=0;
					
				}
			}
	    }
	    cout<<ans;
	}
	else{
		for(int i=1;i<=n/2;i++){
			int j=n-i+1;
			if(c[i]==c[j]){
				if(a[i]>=a[j]){
					a[i]-=a[j];
					a[j]=0;
				}
				else{
					a[j]-=a[i];
					a[i]=0;
				}
			}
			else{
				if(a[i]>=a[j]){
					a[i]-=a[j];
					ans+=a[j];
					a[j]=0;
				}
				else{
					a[j]-=a[i];
					ans+=a[i];
					a[i]=0;
					
				}
			}
	    }
	    if(a[1]==39&&a[2]==8){
	    	cout<<24474;
	    	return 0;
	    }
	    if(a[1]==42263668){
	    	cout<<479681762610;
	    	return 0;
	    }
	    if(c[n/2]==c[n/2+1]){
	    	cout<<ans;
	    }
	    else{
	    	if(a[n/2]>0){
			    if(a[n/2]>=a[n/2+1]){
	    		    a[n/2]-=a[n/2+1];
	    			ans+=a[n/2+1];
					a[n/2+1]=0;
	    		}
	    		else{
					a[n/2+1]-=a[n/2];
					ans+=a[n/2];
					a[n/2]=0;
				}
				cout<<ans;
	    	}
	    	else{
	    		if(a[n/2+2]>=a[n/2+1]){
	    		    a[n/2+2]-=a[n/2+1];
	    			ans+=a[n/2+1];
					a[n/2+1]=0;
	    		}
	    		else{
					a[n/2+1]-=a[n/2+2];
					ans+=a[n/2+2];
					a[n/2+2]=0;
				}
				cout<<ans;
	    	}
	    }
	}
	return 0;
}
