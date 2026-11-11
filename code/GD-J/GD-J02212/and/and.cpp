#include<bits/stdc++.h>
using namespace std;
const int N=2e4+2;
int a[N];
long long b[50];
int n,m,t,sum=0;
void g(int x){
	int sum=1;
	for(int i=1;i<=x;i++){
		sum*=2;
		b[i]=sum;
	}
}
int s(int l,int r){
	int sm=0,k=0;
	for(int i=t;i>=0;i--){
		k+=b[i];
		sm*=2;
		if(a[l]>k||a[r]<k)sm++;
	}
}
void f(int k,int left,int right){
	t--;
	k+=b[t];
	for(int i=left;i<=right;i++){
		if(a[i-1]<k&&a[i]>=k){
			if(right-i+1>m)f(k,i,right);
			else if(right-i+1==m)sum=max(sum,s(i,right));
			else if(i-left>m)f(k-b[t],left,i);
			else if(i-left==m)sum=max(sum,s(left,i));
			else f(k-b[t],left,right);
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a+0,a+n);
	int k=a[n-1];
	t=0;
	while(k!=0){
		k/=2;
		t++;
	}
	g(t);
	f(0,0,n-1);
	cout<<sum;
	return 0;
} 
