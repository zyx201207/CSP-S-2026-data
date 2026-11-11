#include<bits/stdc++.h> 
using namespace std;
int n,m,a[500005],s=0,i;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=1;i<n;i++){
		if(s>=m)break;
		s+=i;
	}
  	cout<<i;
	return 0;
}
