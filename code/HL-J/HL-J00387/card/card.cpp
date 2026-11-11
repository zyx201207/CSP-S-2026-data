#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
long long n,m,a[100095],s=0;
cin>>n>>m;
for(int i=0;i<n;i++){
	cin>>a[i];
}
sort(a,a+n,cmp);
s=a[0]&a[1];
for(int i=0;i<m;i++){	
s=s&a[i];
}
cout<<s;

	return 0;
}
