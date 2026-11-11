#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxx=0;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=n;i>=1;i--){
		long long s=0,ss=0,j=i+1;
		while(s+ss<m){
			
			s+=a[i]-a[j];
			ss+=s;
			j++;
			if(s+ss>=m)continue;
		}
		if(j-i<=n)
			maxx=max(maxx,j-i);
	}
	printf("%lld \n",maxx);
	
	return 0;
}
