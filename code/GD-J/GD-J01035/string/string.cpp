#include<bits/stdc++.h>
using namespace std;
int const N=2e5+10;
long long a[N];
char c[N]; 
int main(){
	freopen("string.in","r",stdin);
	
	freopen("string.out","w",stdout);
	long long n,len=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	long long l=1,r=n,ans=0,sum=0;
	while(l<r){
			
		if(a[l]>a[r]){
			if(c[l]==c[r]){
				
			
				a[l]-=a[r];
				r--;
				
			} else{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			
			}
		}else if(a[l]==a[r]){
			if(c[l]==c[r]){
				l++;r--;
			} else{
				ans+=a[r];
				l++;
				r--;
			}
		}
		else{
			if(c[l]==c[r]){
				
				a[r]-=a[l];
				l++;
			} else{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	
	}
	cout<<ans;
	return 0;
} 
