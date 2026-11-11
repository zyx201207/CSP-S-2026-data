#include<bits/stdc++.h>
using namespace std;
long long n,r,summ;
long long a[200005],s[200005];
char c[200005];
char cz(long long x){
	for(int i=1;i<=n;i++){
		if(x<=s[i])return c[i];
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		r+=a[i];
		s[i]=s[i-1]+a[i];
	}long long sum=r;
	for(long long i=1;i<=sum/2;i++){
		if(cz(i)!=cz(r))summ++;
	}cout<<summ;
	return 0;
}
