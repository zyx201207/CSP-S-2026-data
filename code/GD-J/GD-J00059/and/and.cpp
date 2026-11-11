#include<bits/stdc++.h>
using namespace std;
long long cnt=0;
void f(long long a){
	if(a==0){
	cnt=0;return;
}
	while(a>0){
		cnt*=10;
		int k=a%2;
		cnt+=k;
		a/=2;
	}
	cnt*=10;
	return;
}
long long s(long long x,long long y){
	long long ans=0;
	for(int i=1; i*i<=max(x,y); i++){
		ans*=10;
		int k=x%10;
		x/=10;
		int l=y%10;
		y/=10;
		if(k==l)ans+=1;
	}
	ans*=10;
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
		f(a[i]);
		a[i]=cnt;
		cnt=0;
	}
	long long num=0;
	int k=0,l=0;
	m-=1;
while(m--){
	num=0; 
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(num<s(a[i],a[j])){
				num=s(a[i],a[j]);
				k=i;
				l=j;
			}
		}
	}
	if(m==0){
		break;
	} 
	f(num);
	a[k]=cnt;
	cnt=0;
	a[l]=0;
}
	cout<<num;
	return 0;
} 
