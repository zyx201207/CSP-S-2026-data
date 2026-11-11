#include<bits/stdc++.h>
using namespace std;
long long n,s,ans,a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
	}
	long long l=0,r=s;
	int i=0,j=n-1;
	l+=a[i++];
	while(l<r){
		for(;s-r<l;j--){
			if(c[j]!=c[i])
				ans+=a[j];
			r-=a[j];
		}
		for(;l<=s-r;i++) l+=a[i];
	}
	cout<<ans;
	return 0;
}
