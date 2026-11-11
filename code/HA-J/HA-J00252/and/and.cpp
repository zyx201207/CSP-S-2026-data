#include<bits/stdc++.h>
using namesdpace std;
int n,m;
int a[10000];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}	
if(m==1){
	sort(a+1,a+1+n);
	cout<<a[n];
	return 0;
}
//ÌØÊâµÄA
 sort(a+1,a+1+n);
 cout<<a[n-1];

}
