#include<bits/stdc++.h>
using namespace std;
int n,m,l[200002],d;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	sort(l+1,l+n+1);
	d=l[1];
	if(m==1){
		cout<<l[n];
		return 0;
	}
	if(m==n){
		for(int i=2;i<=n;i++){
			d=(d&l[2]);
		}
		cout<<d;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int d1;
				d1=(i&j);
				d=max(d1,d);
			}
		}
		cout<<d;
		return 0;
	}
	return 0;
}//si dao li tou , ni hai xiang shuo shen me
