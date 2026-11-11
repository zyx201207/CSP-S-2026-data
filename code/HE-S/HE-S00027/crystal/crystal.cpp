#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],ans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(long long i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n,greater<long long>());
	for(long long i=0;i<n;i++){
		long long m1=m,ans1=1;
		for(long long o=i+1;o<n;o++)
			if(m1>=a[i]-a[o])m1-=a[i]-a[o],ans1++;
		if(ans1>ans)ans=ans1;
	}
	printf("%d",n);
	return 0;
} 
