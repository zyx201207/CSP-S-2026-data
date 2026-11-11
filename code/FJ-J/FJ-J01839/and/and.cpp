#include<bits/stdc++.h>
using namespace std;
long long n,m,l[200002],k,p;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		k=max(l[i],k);
	}
	for(int i=1;i<=n;i++){
		if(l[i]!=k)
			p=max(p,l[i]);
	}
	if(m==1){
		cout<<k;
		return 0;
	}
	cout<<p;
	return 0;
}
