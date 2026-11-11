#include<bits/stdc++.h>
using namespace std;
long long n,k,maa=0,ans,maaa=0,p;
long long a[1000000];

int main(){
	freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
	
	
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
   	cin>>p;
	   a[i]=p;
   	maaa=max(maaa,p);
    }
	
	
	
	
	
	
	
	
	
	
	if(k==2){
	
	
	for(long long i=1;i<=n;i++){
    
   	for(long long j=1;j<=n;j++){
   		if(i!=j){
		   
   	ans=a[i];
   	ans=(ans&a[j]);
   	
   	
    
    //cout<<i<<' '<<j<<' '<<ans<<endl;
   	maa=max(maa,ans);
    }}}
   
   
   
   
}else if (k==1){
maa=maaa;
}else if(k==n){
	maa=a[1];
	for(long long i=1;i<=n;i++){
		maa=(maa&a[i]);
	}
	
}
	

   
cout<<maa;
}
