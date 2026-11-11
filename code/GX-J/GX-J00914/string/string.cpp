#include<bits/stdc++.h>
using namespace std;
int n;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int z=1;
	for(int i=1;i<=n;i++){
		int b;
		char c;
		cin>>b>>c;
		for(int j=1;j<=b;j++){
			a[z]=c;
			z++;
		}
	}
	int r=1,l=z-1,as=0;
	while(r<l){
		if(a[r]!=a[l]){
			a[l]=a[r];
			as++;
		}
		r++;
		l--;
	}
	cout<<as;
	return 0;
}
