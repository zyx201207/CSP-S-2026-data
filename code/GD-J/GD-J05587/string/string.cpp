#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],s;
string b[200005];
int p(){
	for(int i=2;i<=n;i++){
		if(b[i]!=b[i-1]) return 0;
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	if(p()==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n/2;i++){
		if(b[i]!=b[n-i+1]){
			if(a[i]>a[n-i+1]){
				b[n-i+1]=b[i];
				s+=a[n-i+1];
			}
			else if(a[i]<a[n-i+1]){
				b[i]=b[n-i+1];
				s+=a[i];
			}
			else if(a[i]==a[n-i+1]){
				b[i]=b[n-i+1];
				s+=a[i];
			}
		}
	}
	for(int i=1;i<=n/2;i++){
		if(a[i]!=a[n-i+1]){
			if(a[i]>a[n-i+1]){
				s+=a[i]-a[n-i+1];
				a[n-i]-=a[i]-a[n-i+1];
				a[n-i+1]=a[i];
			}
			if(a[i]<a[n-i+1]){
				s+=a[n-i+1]-a[i];
				a[i+1]-=a[i]-a[n-i+1];
				a[i]=a[n-i+1];
			}
		}
	}
	cout<<s;
	return 0;
}
