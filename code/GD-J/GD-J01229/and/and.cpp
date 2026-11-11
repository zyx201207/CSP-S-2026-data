#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500000],b[500000];
int main(){
	
	freopen("and3.in","r",stdin);
	freopen("and3.out","w",stdout);
	
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
sort(a+1,a+1+n);
ans=a[n];

for(int i=1;i<m;i++){
	ans=ans&a[n-i];
	
}
cout<<ans;
	return 0;

}

