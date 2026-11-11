#include <bits/stdc++.h>
using namespace std;
int a[10005];
char b[10005];
	char c1[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	int n;cin>>n;
for (int i=0;i<n;i++){
	cin>>a[i]>>b[i];
	c1[b[i]]++;
}
cout<<0;
	return 0;	
} 	
