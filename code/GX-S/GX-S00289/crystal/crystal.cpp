#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long sum=0,ans=0,num,s,y,len,lenn=1000000000005;
long long a[500005];

int main(){
	
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    len=sum/n;
    
    for(long long i=0;i<n;i++){
		for(long long j=1;j<n;j++){
			if(a[j]<a[j-1]){
				long long z=a[j-1];
				a[j-1]=a[j];
				a[j]=z;
			}
		}
	}
	
    for(long long i=0;i<n;i++){
        long long x=a[i]-len;
        if(x<0){
			x*=-1;
		}

        if(x<=lenn){
			lenn=x;
			s=a[i];
			y=i;
		}  
    }
    
    num=m;
    for(long long i=y;i>=0;i--){
        num-=s-a[i];
        if(num>=0){
            ans++;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}
