// GZ-J00629 µËÍûÔÆ
#include<bits/stdc++.h>
char a[200005];
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int c=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int j=c;j<=c+x;j++){
			a[j]=y;
		}
		c+=x;
	}
	int cnt=0;
	for(int i=0;i<=c/2;i++){

		if(a[i]!=a[c-i]) cnt++;
	}
	cout<<cnt;
}
