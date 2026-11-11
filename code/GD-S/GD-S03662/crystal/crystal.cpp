#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[500009],b=0,c=0,d=0,e=1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b+=a[i];
	}
	sort(a,a+n-1);
	b/=n;
	b++;
	if(n<=5000){	for(int i=0;i<n;i++){
		if(a[i]>b) c++;
		else d++;
	}
	if(d>c){
		cout<<d;
	}
	else cout<<c;
	}
else {
	b=a[1]-a[0];
	while(m>=b){
		m-=b;
		e++;
		b+=b;
	}
	cout<<e;
}
	return 0;
}
