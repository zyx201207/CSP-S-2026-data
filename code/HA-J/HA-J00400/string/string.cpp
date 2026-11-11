#include<bits/stdc++.h>
using namespace std;
long long n;
long long l,r;
unsigned long long ans;
struct zifuchuan{
	long long num;
	char zimu;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
		ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i].num >>a[i].zimu ;
	}
	l=0;
	r=n;
	while(l<r){
		if(a[l].zimu ==a[r].zimu ){
			if(a[l].num >=a[r].num ){
				a[l].num =a[l].num -a[r].num ;
					r--;
			}else{
					a[r].num -=a[l].num ;
					l++;	
			}
		}else{
			if(a[l].num >=a[r].num ){
				ans+=a[r].num ;
					a[l].num =a[l].num -a[r].num ;
				r--;
			}else{
					ans+=a[l].num ;
					a[r].num -=a[l].num ;
					l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
