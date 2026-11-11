#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],ans,l,r;
char c[N];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=0,r=n+1;
	for(int i=1,j=n;i<j;){
		int jump=min(a[i],a[j]);
		a[i]-=jump,a[j]-=jump;
		if(c[i]!=c[j])ans+=jump;
		if(a[i]==0)i++;
		if(a[j]==0)j--;
	}
	cout<<ans;
	return 0;
}

