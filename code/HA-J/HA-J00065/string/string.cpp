#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n,a[N],cnt;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int i=1,j=n;
	while(i<j){
		ll sum=min(a[i],a[j]);
		if(c[i]!=c[j]) cnt+=sum;
		a[i]-=sum;a[j]-=sum;
		if(!a[i]) i++;
		if(!a[j]) j--;
	}
	cout<<cnt;
	return 0;
}
