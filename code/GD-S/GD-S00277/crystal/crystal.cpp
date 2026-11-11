#include<bits/stdc++.h>;
using namespace std;
long long a[1000001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
long long n,m,b=0,c;
cin>>n>>m;
for(long long i=1;i<=n;i++){
	cin>>a[i];
	if(a[i]<0){
	flat=1;
	}
}
a[0]=0;
sort(a+1,a+n+1);
for(long long i=1;i<=n;i++){
	for(long long j=1;j<=i;j++){
		b=a[i]+b;
	}
	if(i*a[i+1]<b){
		c=i;
		break;
	}
}
cout<<c-1;
	return 0;
} 
