#include <bits/stdc++.h>
using namespace std;
const int N=1e5*2;
int a[N];
int b[N];
int c[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}if(m==1){
		sort(a+1,a+1+n)
		cout<<a[1];
	}
	if(m==2){
		for(int i=1;i<=n;++i){
			c[1]=0;
			int j=2
			for(;j<=n;++j){
				c[j]=a[i]|a[j];
			}
			sort(c+1,c+n+1);
			b[i]=c[1];
		}
	}
	sort(b+1,b+1+n);
	cout<<b[1];
}
