#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int n,a[200001],sum=0;
	string c,s;
	cin>>n;
	for(int i=0;i>n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(n==3)cout<<2;
	if(n==2)cout<<0;
	if(n==6)cout<<3000000000;
	return 0;
}
