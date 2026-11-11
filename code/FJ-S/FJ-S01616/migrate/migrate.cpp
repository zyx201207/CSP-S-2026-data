#include<bits/stdc++.h>
using namespace std;
int n,d,x[10010];
int main(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	int k=x[2]-x[1];
	d/=k;
	if(d<=1){
		cout<<0;
		return 0;
	}
	else cout<<n-(d*2-1);
	return 0;
}
