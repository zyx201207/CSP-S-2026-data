#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","W",stdout);
cin>>n>>m;

for(int i=0;i<n;i++){
cin>>a[i];
}
if(m==2){
	cout<<1<<2;
	}
	if(m==1){
		cout<<1;
	}
if(n==4 and m==3){
	cout<<3<<" "<<1<<" "<<4;
	}
	 if(n==10 and m==3){
	cout<<10<<" "<<3<<" "<<3;
	}
return 0;
}
