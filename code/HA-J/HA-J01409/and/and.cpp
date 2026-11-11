#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,c,b[200001];
	cin>>a>>c;
	for(int i=1; i<=a; i++) cin>>b[i];
	sort(b+1,b+a+1);
	long long hhy=b[a];
	for(int i=a-1; i>=a-c+1; i--) hhy&=b[i];
	cout<<hhy<<endl;
	return 0;
}