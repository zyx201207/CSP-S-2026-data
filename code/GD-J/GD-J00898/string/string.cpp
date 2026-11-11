#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N];
char c[N]; 
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int i=1,j=n,sum=0;
	while(i<j){
		int x=min(a[i],a[j]);
		a[i]-=x,a[j]-=x;
		if(c[i]!=c[j]) sum+=x;
		if(a[i]==0) i++;
		if(a[j]==0) j--;
	}
	cout<<sum<<"\n";
	return 0;
}
