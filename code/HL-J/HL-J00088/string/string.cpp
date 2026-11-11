#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
struct node{
	long long num;char c;
}a[N];
int n;  
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long al=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		al+=a[i].num;
	}long long ans=al/2;
	int i=1,j=n;
	while(i<j){
		long long k=min(a[i].num,a[j].num);
		if(a[i].c==a[j].c) ans-=k;
		a[i].num-=k;
		a[j].num-=k;
		if(a[i].num==0) i++;
		if(a[j].num==0) j--;
	}
	if(i==j) ans-=a[i].num/2;
	cout<<ans;
	return 0;
}
