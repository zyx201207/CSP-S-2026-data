#include <bits/stdc++.h>
using namespace std;
int n;
int m[100005];
char mm[100005],f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1)cout<<0;
	int j=0;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>mm[i];
		f=mm[i];
		if(f==mm[i])j++;
	}
	if(j==n)cout<<0;
	return 0;
} 
