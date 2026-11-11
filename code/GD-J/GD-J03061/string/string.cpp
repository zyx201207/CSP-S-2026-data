#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
	}
	long long l=1,k=n;
	while(l<k){
		if(c[l]!=c[k]){
			if(a[l]>a[k]){
				ans+=a[k];
			}else if(a[l]<a[k]){
				ans+=a[l];
			}else if(a[l]==a[k]){
				ans+=a[l];
			}
		}
		if(a[l]>a[k]){
		     a[l]-=a[k];
		     k--;
		} 
		else if(a[l]<a[k]){
			a[k]-=a[l-1];
			l++;
		} 
		else if(a[l]==a[k]){
			l++;
			k--;
		}
				
	}
	cout<<ans;
	return 0;
}
