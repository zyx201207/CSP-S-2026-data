#include<bits/stdc++.h>
using namespace std;
int M(int a){
	string b="";
	long long u=0,m=0;
	while(a>0){
		b+=char(a%2+'0');
		u++;
		a/=2;
	}
	for(int i=u-1;i>=0;i--)
	m=m*10+int(b[i]-'0');
	return m;
}
/*int W(int a,int b){
	int o=min(a,b),h=0;
	while(o>0){
		o=min(a,b)
		if(a%10+b%10==2)
		h=h*10+1;
		else
		h=h*10+0;
		a/=10;
		b/=10;
	}
}*/
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n,m,a[10000],b,zd=0,c,ss=0,sss;
	cin>>n>>b;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(ss<a[i]){
			sss=ss;
			ss=a[i];
		}
	}
	for(int i=0;i<n-b+1;i++){
		c=M(a[i]);
		for(int j=i+1;j<i+b;j++){
			c=max(c,c&M(a[j]));
		}
	zd=max(c,zd) ;
		}
	cout<<sss;
	return 0;
} 
//4 2 3 15 12 12
