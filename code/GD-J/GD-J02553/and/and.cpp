#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=0,m=0;
	long long mx=0;
	cin>>n>>m;
	bool a4=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>4) a4=0;
	}
	if(n<2000){
		if(m==1){
			for(int i=1;i<=n;i++) mx=max(mx,a[i]);
		}
		if(m==n) {
			mx=a[1];
			for(int i=2;i<=n;i++) mx=(mx&a[i]);
		}
	}
	if(a4==1&&n>2000){
		bool t1=0,t2=0,t3=0,t4=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) t1=1;
			else if(a[i]==2) t2=1;
			else if(a[i]==3) t3=1;
			else if(a[i]==4) t4=1;
		}
		if(t1==0&&t2==0&&t3==0&&t4==0) mx=4;
		else if(t1==0&&t2==0&&t3==0&&t4==1) mx=4;
		else if(t1==0&&t2==0&&t3==1&&t4==0) mx=3;
		else if(t1==0&&t2==1&&t4==0) mx=2;
		else if(t1==1&&t2==0&&t4==0) mx=1;
		else mx=0;
	}
	cout<<mx;
	return 0;
}
