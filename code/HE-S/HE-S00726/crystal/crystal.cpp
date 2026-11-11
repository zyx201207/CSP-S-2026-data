#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000000],q,b,c=-1000,as,na,e,cb;
void f(int ch,int zh){
	na+=a[ch];
	if(na+m<a[ch]*(as+1)){
		c=max(as,c);
		return ;
	}
	c=max(as,c);
	for(int i=ch+1;i<=n;i++){
		as++;
		f(i,n);
		as--;
	}
	/*if(as+1==n&&na+m>a[ch]*(as+1)){
		
		return ;
	}*/
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m>1000000000){
		cb=a[n];
		for(int i=n;i>=1;i--){
			if(a[i]<0){
				a[i]*=-1;
			}
			m-=(cb-a[i]);
			e++;
			if(m<0){
				cout<<e-1;
				return 0;
			}
		}
		cout<<e;
		return 0;
	}
	f(0,n);
	cout<<c;
	return 0;
} 

