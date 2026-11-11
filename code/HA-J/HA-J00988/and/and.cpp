#include<bits/stdc++.h>
using namespace std;
unsigned long long a,m,n,b[1000005],c,d;
bool l=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	for(unsigned long long i=0;i<n;i++){
		cin>>b[i];
	}
	sort(b,b+n);
	reverse(b,b+n);
	cout<<b[1];
	return 0;
}
