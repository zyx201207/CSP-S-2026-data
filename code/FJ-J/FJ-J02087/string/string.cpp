#include<bits/stdc++.h>
using namespace std;
int n,k=1,m=1,o;
long long a[200005];
char c[200005];
long long l,ans,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	r=(l+1)/2;
	for(int i=1;i<=n;i++){
		r-=a[i];
		if(r<=0){
			o=i;
		}
	}
	//l=50146431
	if(l%2==0){
		for(int i=1;i<=n/2;i++){
			if(a[k]>a[n-m+1]){
				if(c[k]!=c[n-m+1]){
					ans+=a[n-m+1];
				}
				a[k]-=a[n-m+1];
				m++;
			}
			else if(a[k]<a[n-m+1]){
				if(c[k]!=c[n-m+1]){
					ans+=a[k];
				}
				a[n-m+1]-=a[k];
				k++;
			}
			else if(a[k]==a[n-m+1]){
				if(c[k]!=c[n-m+1]){
					ans+=a[k];
				}
				k++;m++;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[k]>a[n-m+1]){
				if(c[k]!=c[n-m+1]){
					ans+=a[n-m+1];
				}
				a[k]-=a[n-m+1];
				m++;
			}
			else if(a[k]<a[n-m+1]){
				if(c[k]!=c[n-m+1]){
					ans+=a[k];
				}
				a[n-m+1]-=a[k];
				k++;
			}
			else if(a[k]==a[n-m+1]){
				if(c[k]!=c[n-m+1]){
					ans+=a[k];
				}
				k++;m++;
			}
		}
	}	
	cout<<ans;
	return 0;
}
