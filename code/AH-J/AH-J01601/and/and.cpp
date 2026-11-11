#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int pw(int num){
	int pww=1;
	for (int i=1;i<=20;i++){
		pww*=2;
		if(num==pww)	return i;
		if(num<pww)	return 0;
	}
	return 0;
}
bool j1(){return n<=20;}
bool j6(){return m==1;}
bool j7(){return m==n;}
bool j8(){return m==2;}
bool j13(){
	for (int i=0;i<n;i++)
		if(!pw(a[i]+1))	return 0;
	return 1;
}
bool j16(){
	int mxx=0;
	for (int i=0;i<n;i++)
		mxx=max(mxx,a[i]);
	return mxx<4;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for (int i=0;i<n;i++)	cin>>a[i];sort(a,a+n);
	if(j6()){cout<<a[n-1];return 0;}
	if(j7()){
		int ans=a[0];
		for (int i=1;i<n;i++)	ans&=a[i];
		cout<<ans;return 0;
	}
	if(j8()){
		int mx=0;
		for (int i=0;i<n;i++){
			mx=max(mx,a[i]&a[i+1]);
			for (int j=i+2;j<n;j++)
				mx=max(mx,a[i]&a[j]);
		}
		cout<<mx;return 0;
	}
	if(j13()){cout<<a[n-m];return 0;}
	if(j16()){
		int c0,c1,c2,c3;
		for (int i=0;i<n;i++){
			if(a[i]==0)	c0++;
			if(a[i]==1)	c1++;
			if(a[i]==2)	c2++;
			if(a[i]==3)	c3++;
		}
		if(m<=c3){cout<<"3";return 0;}
		if(m<=c3+c2){cout<<"2";return 0;}
		if(m<=c3+c2+c1){cout<<"1";return 0;}
		cout<<"0";return 0;
	}
	if(j1()){
		int ans=a[n-m];
		for (int i=n-m+1;i<n;i++)	ans&=a[i];
		cout<<ans;return 0;
	}
	return 0;
}
