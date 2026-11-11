#include<bits/stdc++.h>
using namespace std;
long long t,mi,ans;
string b;
struct node{
	long long s;
	char x;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t>>a[1].s>>a[1].x,mi=a[1].s;
	for(int i=2;i<=t;i++){
		scanf("%lld",&a[i].s);
		cin>>a[i].x,mi=__gcd(mi,a[i].s);
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=a[i].s/mi;j++)
			b+=a[i].x;
	}
	for(int i=0,j=b.size()-1;i<=j;i++,j--)
		if(b[i]!=b[j])ans+=mi;
	printf("%lld",ans);
	return 0;
}
