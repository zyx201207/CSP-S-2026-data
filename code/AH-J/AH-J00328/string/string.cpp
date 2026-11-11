#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
long long ans;
char c[200005];
int main(){
    freopen("string.in","r",stdin);    
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
		cin>>a[i]>>c[i];
	}
	int l=1,r=n,t=2;
	long long d=0,d1;
	while(l<r){
		ans+=d1;
	    if(c[l]!=c[r]){
			if(t==2){
				d=min(a[l],a[r]);
				d1=d;
			    if(a[l]>a[r]) t=0,r--;
		        else if(a[l]<a[r]) t=1,l++;
		        else t=2,l++,r--;
			}else if(t==0){
				ans+=abs(a[l]-d);
				if(d>a[r]) r--;
				else if(d<a[r]) t=1,l++;
				else t=2,l++,r--;	
				d=abs(a[l]-d);
				d1=d;
			}else{
				d1=abs(a[r]-d);
				if(d>a[l]) l++;
				else if(d<a[l]) t=1,l++;
				else t=2,l++,r--;
				d=abs(a[r]-d);	
			}
		}else{
			if(t==2){
				d=abs(a[l]-a[r]);
				d1=d;
			    if(a[l]>a[r]) t=0,r--;
		        else if(a[l]<a[r]) t=1,l++;
		        else t=2,l++,r--;
			}else if(t==0){
				d1=abs(a[l]-d);
				if(d>a[r]) r--;
				else if(d<a[r]) t=1,l++;
				else t=2,l++,r--;	
				d=abs(a[l]-d);
			}else{
				d1=abs(a[r]-d);
				if(d>a[l]) l++;
				else if(d<a[l]) t=1,l++;
				else t=2,l++,r--;
				d=abs(a[r]-d);	
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
