#include<iostream>
#define ll long long
using namespace std;
const int N=200005;
int a[N],tmp[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int j=29;j>=0;j--){
		int k=0;
		for(int i=1;i<=n;i++){
			if((a[i]>>j)&1)tmp[++k]=a[i];
		}
		if(k>=m){
			ans|=(1<<j);
			for(int i=1;i<=k;i++)a[i]=tmp[i];
			n=k;
		}
	}
	cout<<ans;
	return 0;
}
/*
5 3
13 9 10 14 10
10
*/
/*
3 3
9 10 14
8
*/
/*
5 1
1000000 10000 100 1 0
1000000
*/
/*
3 2
0 0 0
0
*/
