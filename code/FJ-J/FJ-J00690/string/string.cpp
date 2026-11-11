#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],ans=0;
string c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1 ; i<=n ; i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1 ; i<=n ; i++){
		if(i!=n){
		if(c[i]==c[n]){
			if(a[i]==a[n]){
				n--;
			}else if(a[i]>a[n]){
				a[i]-=a[n];
				n--;
				i--;
			}else if(a[i]<a[n]){
				a[n]-=a[i];
			}
		}else if(c[i]!=c[n]){
			if(a[i]==a[n]){
				ans+=a[i];
				n--;
			}else if(a[i]>a[n]){
				a[i]-=a[n];
				ans+=a[n];
				i--;
				n--;
			}else if(a[i]<a[n]){
				a[n]-=a[i];
				ans+=a[i];
			}
		}
	}
	}
	cout<<ans;
	return 0;
}
