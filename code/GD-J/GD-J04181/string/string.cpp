#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+9;
ll n;
ll a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld%s",&a[i],&c[i]);
	}
	ll i=1,j=n,I=0,J=0;
	ll sum=0;
	while(i<=n&&j>=1){
		//cout<<sum<<' ';
		if(a[i]-I<a[j]-J){
			if(c[i]!=c[j])sum+=a[i]-I;
			J+=a[i]-I;
			i++;
			I=0;
		}
		else if(a[i]-I>a[j]-J){
			if(c[i]!=c[j])sum+=a[j]-J;
			I+=a[j]-J;
			j--;
			J=0;
		}
		else {
			if(c[i]!=c[j])sum+=a[j]-J;
			i++;
			j--;
			J=0;
			I=0;
		}
	}
	printf("%lld",sum/2);
	return 0;
} 
/*
3
2 a
2 a
1 c
*/

