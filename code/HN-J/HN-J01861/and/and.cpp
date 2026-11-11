#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],mx,b[200005],s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int mx=0,mi=0;
		for(int j=1;j<=n;j++){
			if(a[j]>mx){
				mx=a[j];
				mi=j;
			}
		}
		a[mi]=0;
		b[i]=mx;
	}
	s=b[1];
	for(int i=1;i<=m;i++){
		s&=b[i];
	}
	cout<<s;
	return 0;
}
