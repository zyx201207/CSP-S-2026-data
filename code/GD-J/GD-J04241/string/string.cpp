#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],s;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<r){
		long long x=min(a[l],a[r]);
		a[l]-=x;
		a[r]-=x;
		if(c[l]!=c[r])s+=x;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
		cout<<l<<r<<endl;
	}
	cout<<s;
	return 0;
}
