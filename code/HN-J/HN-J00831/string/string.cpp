#include<bits/stdc++.h>
using namespace std;
int n,m,n2=1;
long long ans;
int a[1000005];
char c[1000005];
string nm;
int main(){
	freopen("stringin","r",stdin);
	freopen("stringout","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n/2;i++){
		if(c[i]!=c[n+1-i]){
			ans+=a[i];
		}
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
