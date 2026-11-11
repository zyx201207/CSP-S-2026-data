#include<bits/stdc++.h>
using namespace std;
long long n,sum=1,ans=0,s1=0,s3=1;
long long a[999999];
char s[999999];
char b[999999],s2;
bool w;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	}
    int q=0;
    if(n%2!=0) q++;
    for(int i=1;i<=n/2+q;i++){
    	if(s1>0){
    		if(w==1){
    			if(s1<=a[n+1-s3]){
    			    if(s2!=b[n+1-s3]) ans+=s1;
    			    a[n+1-s3]-=s1;
    			    s1=0;
			    }
			    else{
			    	if(s2!=b[n+1-s3]) ans+=a[n+1-s3];
			    	s1-=a[n+1-s3];
			    	a[n+1-s3]=0;
			    	s3++;
				}
			}
    		else{
    			if(s1<=a[i]){
    				if(s2!=b[i]) ans+=s1;
    			    a[i]-=s1;
    			    s1=0;
			    }
			    else{
			    	if(s2!=b[i]) ans+=a[i];
			    	s1-=a[i];
			    	a[i]=0;
				}
			}
		}
    	if(b[i]!=b[n+1-s3]){
    		if(a[i]>=a[n+1-s3]){
    			ans+=a[n+1-s3];
    			w=1;
    			s2=b[i];
    			s1=a[i]-a[n+1-s3];
    			s3++;
			}
			else {
				w=0;
				ans+=a[i];
				s2=b[n+1-s3];
				s1=a[n+1-s3]-a[i];
			}
		}
		else{
			s2=b[i];
			if(a[i]>=a[n+1-s3]){
				w=1;
				s1=a[i]-a[n+1-s3];
				s3++;
			}
			else{
				s1=a[n+1-s3]-a[i];
				w=0;
			}
		}
	}
	cout<<ans;
	return 0;
} 
