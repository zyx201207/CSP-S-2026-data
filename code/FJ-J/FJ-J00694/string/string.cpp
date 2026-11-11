#include<bits/stdc++.h>
using namespace std;
long long n;
long long len[200010];
char c[200010];
long long x[200010],y[200010];
string s;
long long l;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	bool b=0;
	for(long long i=1;i<=n;i++){
		cin>>len[i]>>c[i];
		x[i]=x[i-1]+len[i];
		l+=len[i];
		if(c[i]!=c[i-1]&&i>1)b=1;
	}
	ans=l/2-1;
	for(long long i=1;i<=n;i++){
		if(x[i]>l/2){
			ans-=min(l/2-x[i-1]-1,x[i]-l/2);
			break;
		}
		for(int j=1;j<=n-i;j++){
			if(c[i]==c[i+j]&&x[i+j]>l/2){
				if(x[i]>=x[n]-x[i+j-1])
					ans-=min(x[i]-x[i-1],x[n]-x[i+j-1]);
			}
		}
	}
	if(b)cout<<ans;
	else cout<<0;
	return 0;
}
