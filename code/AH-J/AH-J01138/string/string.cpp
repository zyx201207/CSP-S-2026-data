#include<bits/stdc++.h>
using namespace std;

int n,sum=0;
int a[200005];
char c[200005];
int flag=1;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i!=1&&c[i]!=c[i-1]) flag=0;
		sum+=a[i];
	}
	if(n==1) cout<<0;
	if(flag==1) cout<<0;
	return 0;
}

