#include<bits/stdc++.h>
using namespace std;
int n,mmax=-1,a,u=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		mmax=max(a,mmax);
		if(a<mmax){
			u=max(u,a);
		}
	}
	int c=u & mmax;
	cout<<c;
	return 0;
}
