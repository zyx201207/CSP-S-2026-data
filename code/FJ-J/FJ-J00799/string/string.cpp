#include<bits/stdc++.h>
using namespace std;
long long a,n,m,y=1,u;
char b,c[1000000000005],d[1000000000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		u+=a;
		for(int j=y;j<=a;j++){
			y++;
			c[j]==b;
		}
	}
	for(int i=u;i>0;i++){
		d[i]==c[u-i];
	}
	for(int i=1;i<=u;i++){
		if(d[i]!=c[i])m++;
	}
	cout<<m;
	return 0;
}

