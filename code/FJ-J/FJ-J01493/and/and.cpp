#include<bits/stdc++.h>
using namespace std;
long long n,m,a[222222],s,d[222222],x,b[222222],t1,t2,t3,t4;
bool c(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],x=max(x,a[i]);
	if(x<=4){
		for(int i=1;i<=n;i++){
			if(a[i]==4)t4++;
			if(a[i]==3)t3++;
			if(a[i]==2)t2++;
			if(a[i]==1)t1++;
		}
		if(t4>=m)cout<<4;
		else if(t3>=m)cout<<3;
		else if(t2+t3>=m)cout<<2;
		else if(t3+t1>=m)cout<<1;
		else cout<<0;
		return 0;
	}
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==n){
		s=a[1];
		for(int i=2;i<=n;i++)s&=a[i];
		cout<<s;
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				s=max(s,a[i]&a[j]);
			}
		}
		cout<<s;
		return 0;
	}
	sort(a+1,a+n+1,c);
	s=a[1];
	for(int i=2;i<=m;i++)s&=a[i];
	cout<<s;
	return 0;
}
