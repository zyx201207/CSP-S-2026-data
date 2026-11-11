#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
const int N=2e5+5;
int n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){//6
		int maxn=-1;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}
	else if(m==n){//7
		int x=1;
		for(int i=1;i<=n;i++){
			x&=a[i];
		}
		cout<<x;
	}
	else if(m==2){//8~10
		int maxn=-1,x;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				x=a[i]&a[j];
				maxn=max(maxn,x);
			}
		}
		cout<<maxn;
	}
	else if(m==n-1){//11~12
		int x=1,maxn=-1,b,cnt=0;
//		for(int i=1;i<=n;i++){
//			b&=a[i];
//		}
		for(int i=1;i<=n;i++){
			cnt++;
			b=0x3f3f3f3f;
			for(int j=1;j<=n;j++){
				if(j!=cnt){
					b&=a[j];
				}
			}
			maxn=max(maxn,b);
		}
		cout<<maxn;
	}
	else{//A,B
		sort(a+1,a+1+n,cmp);
		int x=0x3f3f3f3f;
		for(int i=1;i<=m;i++){
			x&=a[i];
		}
		cout<<x;
	}
	return 0;
}
/*
要求:
	从n个非负整数中选出恰好m个,
	使得选出的m个数的二进制按位与的值最大



*/
