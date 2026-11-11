#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum,l,s=0,q;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	char e;
	for(int i=1;i<=n;i++)scanf("%lld",&q),a[i]=q,cin>>b[i];
	int i=1,j=n;
	while(i<j){
		if(b[i]!=b[j]){
			sum+=min(a[i],a[j]); 
		}
		//cout<<a[i]<<" "<<a[j]<<endl;
		l+=a[j];
		int minn=min(a[i],a[j]);
		a[i]-=minn;
		a[j]-=minn;
		if(a[j]<=0)j--;
		if(a[i]<=0)i++;
	}
	cout<<sum;
	return 0;
} 
