#include<bits/stdc++.h>
using namespace std;

long long n,ans=0;
struct node{
	long long x;
	char c;	
}a[200005];

void f(int l,int r){
	if(l>=r)return;
	if(a[l].x==a[r].x&&a[l].c==a[r].c){//左右两边相同 
		f(l+1,r-1);return;
	}
	if(a[l].x==a[r].x&&a[l].c!=a[r].c){//左右两边字不同 
		ans+=a[l].x;f(l+1,r-1);return;
	}
	if(a[l].x!=a[r].x&&a[l].c==a[r].c){//左右两边长度不同 
		if(a[l].x>a[r].x){
			a[l].x=a[l].x-a[r].x;
			f(l,r-1);
			return;
		}
		else if(a[l].x<a[r].x){
			a[r].x=a[r].x-a[l].x;
			f(l+1,r);
			return; 
		}
	}
	if(a[l].x!=a[r].x&&a[r].c!=a[l].c){//都不一样 
		ans+=min(a[r].x,a[l].x );
		if(a[r].x>a[l].x){
			a[r].x=a[r].x-a[l].x;
			f(l+1,r);return;
		}
		else if(a[r].x<a[l].x){
			a[l].x=a[l].x-a[r].x;
			f(l,r-1);return;
		}
	}
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	f(1,n);
	cout<<ans;
	return 0;
}
