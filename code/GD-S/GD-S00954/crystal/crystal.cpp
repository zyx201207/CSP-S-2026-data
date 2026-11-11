#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],s[N];
bool check(int mid){
	int cost=0,maxc=0;
	for(int l=1;l<=n;l++){
		int r=l+mid-1;
		if(r>n)break;
		int k=mid*a[r];
		int p=s[r]-s[l-1];
		cost=k-p;
		if(cost<=m)return true;//¿ÉÐÐ 
		//if(cost>m)return false;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=0,r=n+1;
	while(r-l>1){
		int mid=l+r>>1;
		if(check(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	cout<<l;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

hack:

7 6
2 2 4 4 5 5 6 

AC!!! 
*/
