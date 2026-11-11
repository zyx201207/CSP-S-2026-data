#include<bits/stdc++.h>
using namespace std;
int n,m,x,mx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(m==1){
			mx=max(mx,x);
		}else{
			if(i==1) mx=x;
			else mx&x;
		}
	}
	cout<<mx;
	return 0;
}
