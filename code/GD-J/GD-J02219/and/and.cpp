#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long int a[N],ma,k;

bool check(long long int x){
	long long int sum=1;
	for(int i=1;i<=40;i++){
		sum*=2;
		if(sum-1==x)return true;
		if(sum>=x)return false;
	}return false;
}
int fun(long long int x,long long int y){
	string s;
	while(x!=0&&y!=0){
		if(x%2==1&&y%2==1)s=s+'1';
		else s=s+'0';
	}
	long long int val=0,len=s.size();
	for(int i=len-1;i>=0;i--){
		val=val*10+char(s[i]-'0');
	}return val;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool f=true;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		ma=max(ma,a[i]);
		if(!check(a[i]))f=false;
	}
	if(m==1||f==true){
		cout<<ma;
		return 0;
	}long long int sum=a[n];
	sort(a+1,a+n+1);
	for(int i=n-1;i>=n-m;i--){
		sum=fun(sum,a[i]);
	}
	cout<<sum;
	return 0;
}
