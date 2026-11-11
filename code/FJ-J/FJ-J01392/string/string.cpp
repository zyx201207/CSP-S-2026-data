#include <bits/stdc++.h>
using namespace std;

long long a[200010];
char c[200010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,len=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a1;
		cin>>a1>>c[i];
		len+=a1;
		a[i]=a[i-1]+a1;
	}
	long long ans=0,j=1,k=n;
	for(int i=1;i<=len/2;i++){
		if(!(i>a[j-1]&&i<=a[j])) j++;  //l-c[j]
		if(!(len-i+1>a[k-1]&&i<=a[k])) k--; //r-c[k]
		if(c[j]!=c[k])	ans++;
	}
	cout<<ans;
}

