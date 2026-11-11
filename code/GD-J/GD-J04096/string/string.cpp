#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long n,cnt=0;
string a;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++) {
		int q1;
		char q2;
		cin>>q1>>q2;
		for(int i=1;i<=q1;i++) a+=q2;
	}
	long long k=a.size()-1;
	for(int i=0;i<k/2;i++)
		if(a[i]!=a[k-i])
			cnt++;
	cout<<cnt;
	return 0;
}
