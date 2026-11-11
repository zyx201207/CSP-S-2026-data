#include<bits/stdc++.h>
using namespace std;
long long n,x,len,_1,_2,ans;
struct node{
	long long b,e;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>x>>a[i].c;
		a[i].b=a[i-1].e+1,a[i].e=a[i].b+x-1;
		len+=x;
	}
	for(long long i=1;i<=len/2;i++){
		for(long long j=1;j<=n;j++) if(a[j].b<=i&&a[j].e>=i){_1=a[j].c;break;}
		for(long long j=n;j>=1;j--) if(a[j].b<=len-i+1&&a[j].e>=len-i+1){_2=a[j].c;break;}
		if(_1!=_2) ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
