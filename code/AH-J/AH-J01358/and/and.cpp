#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[100100],b,c;
bool ff=0;
int main(){
	
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
while(n!=1){
	if(n%2==1){
		ff=0;
	break;
}
	n/=2;
	ff=1;
}
for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
	sort(a,a+n);
	cout<<a[n-1];
}else if(m==2){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		b=max(a[j+1]&a[j],b);
	}
	c=max(c,b);
	b=0;
	cout<<c;
}else if(ff){
	sort(a,a+n);
	cout<<a[n-1]&a[n-2];
}else{
	
	sort(a,a+n);
	cout<<a[n-2];
}
return 0;
}
