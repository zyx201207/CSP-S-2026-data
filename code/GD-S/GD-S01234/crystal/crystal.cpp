#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010];
int op,sc;
bool p=false;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2){
			sc=op;
		    op=a[i]-a[i-1];
		    if(sc!=op) p=true;
		}
	}
	if(p==false){
		long long anser=0;
		int jj=1;
		int o=0;
	   while(1){
	   	  if(anser>m){
             cout<<o;
			 return 0;	   	  	
 			}
	   	  anser+=a[jj];
	   	  jj++;
	   	  o++;
	   }
	}
	long long ans=-1,sum=0;
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
	    sum=0;
	    long long w=m;
		for(int j=i-1;j>=1;j--){
			if(w-(a[i]-a[j])>=0){
				sum++;
				w-=a[i]-a[j];
			} else{
				break;
			}
		}
		ans=max(sum+1,ans);
	}
	cout<<ans;
	return 0;
} 
