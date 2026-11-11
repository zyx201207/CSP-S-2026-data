#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
int a[N];
char c[N];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<=n/2;){
		int x=min(a[i],a[j]);
		if(c[i]!=c[j]) ans+=x;
		a[i]-=x,a[j]-=x;
		if(!a[i]) i++;
		else if(!a[j]) j--;
	}
	cout<<ans<<'\n';
	return 0;
}