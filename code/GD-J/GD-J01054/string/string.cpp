#include<bits/stdc++.h>
using namespace std;
const long long N=2*1e5+5;
struct node{
	long long val;
	char x;
}a[N];
int n=0,ans=0,m=0;
char x;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++){
		
		cin>>a[i].val>>a[i].x;
		
		
		
	}
	if(n==1||n==2){
		cout<<0;
		return 0;
	}
	long long L=1,R=n;
	while(L<=R){
		if(a[L].x!=a[R].x){
			long long max1=0,min1=0;
			max1=max(a[L].val,a[R].val);
			min1=min(a[L].val,a[R].val);
			ans=ans+max1;
		}
		L++;
		R--;
	}
	cout<<ans;
	return 0;
}
