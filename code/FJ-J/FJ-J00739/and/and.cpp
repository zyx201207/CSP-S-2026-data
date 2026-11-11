#include<bits/stdc++.h>
using namespace std;
int n,m,m1=1;
long long a[200010],x=-1;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(nullptr);
cin>>n>>m;
for(int i=0;i<n;i++){
	cin>>a[i];
	x=(x&a[i]);
}
if(n==m){
	cout<<x<<"\n";
	return 0;
}
if(m==1){
	sort(a,a+n);
	cout<<a[n-1]<<"\n";
	return 0;
}
x=0;
for(int i=0;i<n;i++){
	long long y=a[i];
	m1=i+1;
	for(int j=i+1;j<n;j++){
		y=(y&a[m1]);
		m1++;
		if(m==m1-i){
			x=max(x,y);
		    y=a[i];
		    m1=j-1;
		}
	}
}
cout<<x<<"\n";
return 0;
}
