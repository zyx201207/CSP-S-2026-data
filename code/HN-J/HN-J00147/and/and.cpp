#include<bits/stdc++.h>
using namespace std;

long long n,m,s[9000005];
int main(){
	
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		s[i]=i;
	}
	
	sort(s,s+n+1);
	
	cout<<s[m];
	
	return 0;
}



