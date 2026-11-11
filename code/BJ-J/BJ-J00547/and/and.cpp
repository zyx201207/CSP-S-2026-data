#include<bits/stdc++.h>
using namespace std;
long long n,m,l=0,o=-1,a[10001],p[1001];
void ad(){
	for(long long i=l;i<=n;i++){
		p[l]=a[i];
		if(l==m){
			int k;
			for(long long j=m;j>=1;j--){
				k=k&p[i];
			}
			if(k>o){
				o=k;
			}
			return ;
		}
		l++;
		ad();
		l--;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	ad();
	cout<<o;
	return 0;
}
