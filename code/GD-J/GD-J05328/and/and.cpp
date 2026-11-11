#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);

int n,m,s=0;
cin>>n>>m;
int a[n+1];
for(int i=1;i<=n;i++){
	cin>>a[i];
	if(s<a[i] and a[i-1]){
	s=a[i] and a[i-1];
	}
}
cout<<s;
freopen("and.out","w",stdout);
    return 0;
}
