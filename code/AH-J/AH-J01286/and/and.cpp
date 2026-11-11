#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
int ans=0;
bool check(int x){
	int sum=0;
	for(int i=1;i<=n;i++){
		if((a[i]&x)==x)sum++;
	}
	return sum>=m;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=29;i>=0;i--){
		if(check(ans+(1<<i))){
			ans+=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}
