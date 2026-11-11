#include <bits/stdc++.h>
using namespace std;

long long a[200002],dif=0,b=1,e;
char c[200002];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	e=n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while (b<e){
		int del=min(a[b],a[e]);
		if (c[b]!=c[e]){
			dif+=del;
		}
		a[b]-=del;
		a[e]-=del;
		if (a[b]==0){
			b++;
		}
		else{
			e--;
		}
	}
	cout<<dif; 
	return 0;
}

