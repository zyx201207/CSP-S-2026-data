#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
int sec(int a){
	int ans=0;
	while(a>0){
		ans=ans*10+a%2;
		a/=2;
	}
	return ans;
}
int cont(int a){
	int cnt=0;
	while(a>0){
		int t=a%10;
		if(t==1)
		cnt++;
		a/=10;
	}
	return cnt;
}
bool cmp1(int a,int b){
	a=sec(a);
	b=sec(b);
	return cont(a)>cont(b);
}
bool cmp2(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp1);
	sort(a+1,a+n+1,cmp2);
	for(int i=2;i<=m;i++)
	{
		a[i]=a[i]&a[i-1];
	}
	cout<<a[m];
	return 0;
} 
