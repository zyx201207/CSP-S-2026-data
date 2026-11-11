#include<bits/stdc++.h>
using namespace std;
int main {
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	string str,ss;
	int n,m,x,y;
	cin>>n>>m;
	int a[n+1],b[m+1];
	char a1[n+1];
	for(int i=1; i<=n; i++) {
		cin<<a[i];
		a1[i]=a[i];
		str+=a1[i];
	}
	for(int i=1; i<=n; i++) {
		x=i;
		for(int j=i; j<=n; j++) {
			y=str.find(x,j-x,str[j]);
			if(y=0) {
				continue;
			} else {
				x=y;
			}
		}
		for(int j=x;j<=n;j++){
			b[a[j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<b[i];
	}
	return 0;
}
