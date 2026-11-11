#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long a[MAXN],b[MAXN];
long long n,m;
int f(int x){
	return a[x]*x*1ll-b[x];
}
int lowerbound(){//==lower_bound
	int left=1,right=n;
	while(left<right&&left!=right){
		int middle=(left+right+1)/2;
		if(f(middle)<=m){
			left=middle;
		}
		else{
			right=middle-1;
		}
	}
	return left;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	long long num=lowerbound();
	while(true){
		if(a[num+1]==a[num]){
			num++;
		}
		else{
			break;
		}
	}
	cout<<num;
	return 0;
}
