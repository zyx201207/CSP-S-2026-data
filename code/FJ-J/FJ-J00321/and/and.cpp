#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,cnt;
	cin>>n>>m;
	int a[n+5],c[m+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int p=0,o=0;
		for(int j=1;j<=n;j++){
			if(a[j]>p){
				p=a[j];
				o=j;
			}
		}
		a[o]=0;
		c[i]=p;
	}
	cnt=c[1];
	for(int i=2;i<=m;i++)cnt=c[i]&cnt;
	cout<<cnt;
	return 0;
}
