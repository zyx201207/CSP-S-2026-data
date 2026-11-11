#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,non,non2,p,z;
int a[N];
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int res=0;
	non=a[1];
	non2=a[0];
	p=a[0];
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			p=min(p,a[i]);
			p=min(p,a[j]);
		}
	}
	int p2=p;
	z=a[0];
	p=a[1];
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(a[i]!=p2 && a[j]!=p2){
				p=min(p,a[i]);
				p=min(p,a[j]);
			}
		}
	}
	cout<<p2<<" "<<p;
	return 0;
}
