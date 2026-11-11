#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int b[maxn];
struct p{
	int cry;
}a[maxn];
bool cmp(p x,p y){
	return x.cry <y.cry ;
}
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].cry ;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(i<n){
			if(a[i+1].cry >a[i].cry )
				b[i]=a[i+1].cry -a[i].cry ;
			else b[i]=a[i].cry -a[i+1].cry ;
		}
	}
	int mx=b[1],x,y;
	for(int i=2;i<=n;i++){
		if(mx<b[i]){
			mx=b[i];
			x=i-1;
			y=n-2-x;
		}
	}
	int mi=b[x+1],ans;
	if(x>y){
		for(int i=x+1;i>=1;i--){
			if(mi>b[i]){
				mi=b[i];
				ans=i;
			}
		}
		cout<<x+1;
	}
	if(y>x){
		for(int i=x+1;i<=n-1;i++){
			if(mi>b[i]){
				mi=b[i];
				ans=i;
			}
		}
		cout<<y+1;
	}
	
	return 0;
} 

