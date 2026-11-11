#include<bits/stdc++.h>
using namespace std;
long long m,n,ma,f,mi;
long long a[200005];
int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
	}
	if(m==1){
		cout<<ma;
		return 0;
	}else if(f==0){
		cout<<mi;
		return 0;
	}
}