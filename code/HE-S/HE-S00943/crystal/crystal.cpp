#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],x=1,sum=1,maxx=0;
bool check(){
	int s=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=s) return false;
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(check()){
		while(m>=x*(a[2]-a[1])){
	    	sum++;
	    	x+=sum;
     	}
    	cout<<sum;
    	return 0;
  	}else{
  		sort(a+1,a+n+1);
  		for(int i=n;i>=1;i--){
  			long long numm=m,anss=0;
  			for(int j=n-1;j>=1;j--){
  				if(numm>=0){
  					numm-=a[i]-a[j];
  					anss++;
				}else{
					numm+=a[i]-a[j+1];
					anss--;
					break;
				}
			}
			maxx=max(maxx,anss);
			
		}
		cout<<maxx;
		return 0; 
	}
	return 0;
}
