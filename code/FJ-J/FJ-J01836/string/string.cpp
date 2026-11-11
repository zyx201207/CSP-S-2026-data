#include<bits/stdc++.h>
using namespace std;
long long ans,p,q;
int n,r,z,a[200010];
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=2;i<=n+1;i++){
		cin>>a[i]>>s[i];
		p+=a[i];
	}
	if(p%2==0){
		q=p/2;
		for(int i=2;i<=n+1;i++){
			if(q>a[i]){
				q-=a[i];
			}
			else{
				r=i-1;
				z=i;
				break;
			}
		}
		for(int i=1;i<=r;i++){
			a[i]=a[i+1];
			s[i]=s[i+1];
		}
		a[r]=q;
		a[z]-=q;
		while(r>=1 && z<=n+1){
			if(a[r]>=a[z]){
				if(s[r]!=s[z]){
					ans+=a[z];
				}
				a[r]-=a[z];
				z++;
			}
			else{
				if(s[r]!=s[z]){
					ans+=a[r];
				}
				a[z]-=a[r];
				r--;
			}
		}
	}
	else{
		q=p/2+1;
		for(int i=2;i<=n+1;i++){
			if(q>a[i]){
				q-=a[i];
			}
			else{
				r=i-1;
				z=i;
				break;
			}
		}
		for(int i=1;i<=r;i++){
			a[i]=a[i+1];
			s[i]=s[i+1];
		}
		a[r]=q-1;
		a[z]-=q;
		while(r>=1 && z<=n+1){
			if(a[r]>=a[z]){
				if(s[r]!=s[z]){
					ans+=a[z];
				}
				a[r]-=a[z];
				z++;
			}
			else{
				if(s[r]!=s[z]){
					ans+=a[r];
				}
				a[z]-=a[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}