#include<bits/stdc++.h>
using namespace std;
int n;
long long s,c,sum,a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int j=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	for(int i=1;i<=n+1;i++){
		s+=a[sum+1-i];
		if(a[i+1]==(n+1)/2){
			c+=a[i+1];
			cout<<c;
			return 0;
		}
		a[i+1]+=a[i]-a[sum+1-i];
		if(b[i]!=b[sum+1-i]) c+=s;
	}
	cout<<c;
	return 0;
}
