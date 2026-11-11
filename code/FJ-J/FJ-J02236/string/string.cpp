#include<bits/stdc++.h>
using namespace std;
long long x=0,ans=0;
string b;
int n;
struct s{
	int sl;
	string zm;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].sl>>a[i].zm;
		for(long long j=1;j<=a[i].sl;j++){
			b+=a[i].zm;
		}
		x+=a[i].sl;
	}
	for(long long i=1;i<=x/2;i++){
		if(b[i]!=10^(x-i)){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
