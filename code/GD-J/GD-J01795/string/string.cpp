#include<bits/stdc++.h>
using namespace std;
long long n,sum;

struct jgt{
	long long a;
	string s;
} a[2000005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].a>>a[i].s;
	}
	for(long long i=1;i<=n;i++){
		sum+=a[i].a;
	}
	cout<<sum/2;
	return 0;
}
