#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

long long n,a[200005],sum=0;
char c[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;){
		ll k=min(a[i],a[j]);
		a[i]-=k;
		a[j]-=k;
		if(c[i]!=c[j]){
			sum+=k;
		}
		if(a[i]==0) i++;
		if(a[j]==0) j--;
	}
	cout<<sum;
	return 0;
}
