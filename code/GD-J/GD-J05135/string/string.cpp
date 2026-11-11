#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		cin>>b[i];
	}
	if(n<=2){
		if(n<=1) {cout<<0;return 0;}
		else{
			if(b[1]==b[2]) {cout<<0;return 0;}
			else {cout<<min(a[1],a[2]);return 0;}
		}
	}
	else{
		int n1,sum=0;
		if(n%2==0) n1=n/2;
		else n1=(n-1)/2;
		 for(int i=1,j=n;i<=n1;i++,j--) if(b[i]!=b[j]) sum++;
		cout<<sum;
		return 0;
	}
	return 0;
}
/*
12
1 a 1 b 1 a 1 c 1 c 1 b 1 b 1 a 1 a 1 a 1 b 1 a*/

