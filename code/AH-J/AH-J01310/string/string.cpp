#include<bits/stdc++.h>
using namespace std;
struct ss{
	long long x;
	string s;
}a[200010];
 long long L;
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].s;
        L+=a[i].x;
    }
    long long cnt=0;
    long long  ans=0;
   long long l=1,r=n;
   while((L-cnt)!=1&&l<r){
	   cnt+=min(a[l].x,a[r].x);
	   if(a[l].s!=a[r].s&&a[l].x>a[r].x){
		   ans+=a[r].x;
		   a[l].x-=a[r].x;
		   r--;
		   
	    }else if(a[l].s!=a[r].s&&a[l].x<a[r].x){
			ans+=a[l].x;
			a[r].x-=a[l].x;
			l++;
			
		}else if(a[l].s!=a[r].s&&a[l].x==a[r].x){
			ans+=a[r].x;
			l++;
			r--;
			
		}else if(a[l].s==a[r].s&&a[l].x<a[r].x){
			
			a[r].x-=a[l].x;
			l++;
	
		} else if(a[l].s==a[r].s&&a[l].x>a[r].x){
		  
		   a[l].x-=a[r].x;
		   r--;	   
	    }else{
			l++;
			r--;
			
		}
			
   }
   cout<<ans ;
    return 0;
}
