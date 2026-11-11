#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[2*100000+5],b[2*100000+5],z=1;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+1+n,cmp);
		cout<<a[1];
	}
	if(m==n){
		int f=a[1];
		for(int i=2;i<=n;++i){
			f=f&a[i];
		}
		cout<<f;
	}
	if(m==2){
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<n;++j){
				b[z++]=a[i]&a[j];
			}
		}
		sort(b+1,b+1+n,cmp);
		cout<<b[1];
	}
	return 0;
} 
