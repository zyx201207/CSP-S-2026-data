#include <bits/stdc++.h>
using namespace std;
int a[214514];
int a3,a2,a1/*,a0*/;
int n,m,mxa;
void solve1(){
	sort(a+1,a+n+1);
	cout<<a[n];
}
void solve2(){
	sort(a+1,a+n+1);
	cout<<a[1];
}
void solve3(){
	sort(a+1,a+n+1);
	cout<<(a[n]&a[n-1]);
}
void solve4(){
	sort(a+1,a+n+1);
	int k=a[n];
	for(int i=n;i>=3;i--){
		k&=a[i];
	}
	cout<<max(k&a[2],k&a[1]);
}
void solve5(){
	sort(a+1,a+n+1);
	cout<<a[1];
	if(a3>=m)cout<<3;
	else if(a2+a3>=m)cout<<2;
	else if(a3+a1>=m)cout<<1;
	else{cout<<0;
	}
}

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==3)a3++;
		if(a[i]==2)a2++;
		if(a[i]==1)a1++;
		//if(a[i]==0)a0++;
		
		mxa=max(a[i],mxa);
	}
	if(m==1){
		solve1();
	}
	if(m==n){
		solve2();
	}
	if(m==2){
		solve3();
	}
	if(m==n-1){
		solve4();
	}
	if(mxa<4){
		solve5();
	}
	return 0;
}
