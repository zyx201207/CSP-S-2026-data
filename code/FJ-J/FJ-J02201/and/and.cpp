#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m,f=0,x;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[i]=x;
		f=max(f,x);
	}
	if(m==1){
		cout<<f<<endl;
		return 0;
	}
	return 0;
}