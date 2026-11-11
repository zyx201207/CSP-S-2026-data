#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m,ans,maxn=0,len,d[100000],a[100000];
char c,pos;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>c;
		a[i]=c-'A'+1;
		d[a[i]]+=m;
		len+=m;
		maxn=max(d[a[i]],maxn);
	}
	
	long long x=len-maxn;
	//cout<<len<<" "<<maxn;
	if(x%2) ans=x-1;
	else ans=x;
	cout<<ans;
	return 0;
} 


