#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[2000009];
int f[84545455];
int n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int len =0;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int i=0;i<n;i++){
		cin>>a[i];
		len++;}
		int ye=a[1]-a[2]
		if(ye>=0){
			d=d/ye;
		}else{
			d=d/(0-ye);
		}
		int q=n-(2*d/-1);	
		cout<<q;
	}
}
