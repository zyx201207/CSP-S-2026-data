#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,a[1000000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=n;i>=1;i--){
		cnt+=a[i];
		if(cnt>=m){
			cout<<i;
			return 0;
		}
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=a[i];
		if(cnt>=m){
			cout<<i;
			return 0;
		}
	}
	return 0;
}
