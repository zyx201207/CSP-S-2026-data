#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
//string s[N];
int a[N],m,n,maxn;
//string chai(int x){
//	string ans="";
//	int sum=1;
//	for(int j=1;j<=30;j++){
//		sum*=2;
//	}
//	for(int i=31;i>=1;i--,sum/=2){
//		if(x/sum>=1){
//			ans=ans+'1';
//			x-=sum;
//		}
//		else ans=ans+'0';
//	}
//	return ans;
//}
//bool cmp(string x,string y){
//	return x>y;
//}

bool cmp1(int x,int y){
	return x>y;
}
void check1(){
	cout << maxn;
}

void check2(){
	int ans=a[1];
	for(int i=2;i<=n;i++){
		ans=ans&a[i];
	}
	cout << ans;
}

void check3(){
	int maxnn=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			maxnn=max(maxnn,a[i]&a[j]); 
		}
	}
	cout << maxnn;
}

void check4(){
	int maxnn=0;
	for(int j=1;j<=n;j++){
		int ans=INT_MAX;
		for(int i=1;i<=n;i++){
			if(i==j) continue;
			ans=ans&a[i];
		}
		maxnn=max(maxnn,ans);
	}
	cout << maxnn;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		maxn=max(maxn,a[i]);
		//s[i]=chai(a[i]);
	}
	//sort(s+1,s+1+m,cmp);
	sort(a+1,a+1+n,cmp1);
	if(m==1) check1();
	else if(m==n) check2();
	else if(m==2) check3();
	else if(m==n-1) check4();
	else{
		int ans=a[1];
		for(int i=2;i<=m;i++){
			ans=ans&a[i];
		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

