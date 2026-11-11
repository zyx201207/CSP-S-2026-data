#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N];
int ans,n,m;
int get_ans(int id,int m){
	int res=0;
	for(int j=id-1;j>=1;j--){
		if(a[id]-a[j]>m)  return res+1;
		res++;
		m-=a[id]-a[j];
	}
	return res+1;
}
void op(){
	int num=a[2]-a[1];
	int maxn=sqrt(2*m/num);
	for(int i=min(n,maxn+1);i>=2;i--){
		if(i*(i-1)<=2*m/num){
			cout<<i;
			return;
		}
	}
	cout<<"0";
	return;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int flag=1;
	int num=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=num){
			flag=0;
			break;
		}
	}
	if(flag){
		op();
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans=max(ans,get_ans(i,m));
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3-1 2 2 7

*/
