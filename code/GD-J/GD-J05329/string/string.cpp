#include <bits/stdc++.h>
using namespace std;
string s;
int x,sum;
long long a[200000000],ans,y=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>x;
	for(int i=1;i<=x;i++){
		long long b; char c;
		cin>>b>>c;
		for(long long j=y;j<=y+b-1;j++)
			a[j]=c-'a'+1;
		y+=b;
	}
	y-=1;
	for(int i=1;i<=y/2;i++)
		if(a[i]!=a[y+1-i]) ans++;
	cout<<ans;
	return 0;
}
