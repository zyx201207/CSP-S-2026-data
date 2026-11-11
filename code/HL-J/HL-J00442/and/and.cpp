#include <bits/stdc++.h>
using namespace std;
int n,m,a[200001],mx=0,a1,x;
int main(){
	freopen("and3.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	a1=int(a[0] and a[1]);
	for(int i=2;i<m;i++){
		
		x=int(a1 and a[i]);
		if(x>mx){
			mx=x;
		}
	}
	cout<<mx;
}
