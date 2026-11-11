#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long n,m,k=0;
cin>>n>>m;
for(int i=0;i<n;i++){
	cin>>a[i];
	if(a[i]>k){
		k=a[i];
	}
}
if(m==1){
	cout<<k;
}	
}
