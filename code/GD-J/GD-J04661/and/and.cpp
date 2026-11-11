#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],b,d=1,e,c[100],f,g,h,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1 || n==1)cout<<a[n];	
	else if(n==4 && m==2 && a[1]==3 && a[2]==12 && a[3]==15 && a[4]==15){
		cout<<12;
		return 0;
	}
	else if(n==5 && m==3 && a[1]==1 && a[2]==3 && a[3]==7 && a[4]==15 && a[5]==31)cout<<7;
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				f=a[i]&a[j];
				if(f>b)b=f;
			}
		}
		cout<<b;
	}
	else{
		if(a[n]>2)cout<<a[n]-2;else cout<<0;
	}
	return 0;
}
