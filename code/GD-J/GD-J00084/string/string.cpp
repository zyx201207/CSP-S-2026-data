#include<bits/stdc++.h>
using namespace std;
char c[200005];
int n;
long long a[200005],ans,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long l=1,r=sum,le=1,ri=n;
	sum/=2;
	while(r>sum){
		int m=min(a[le],a[ri]);
		l+=m;
		r-=m;
		a[le]-=m;
		a[ri]-=m;
		if(c[le]!=c[ri]) ans+=m;
		if(a[le]==0) le+=1;
		else ri-=1;
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
