#include<bits/stdc++.h>
using namespace std;
long long a[10101010],dp[10101000],x=1,mx;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[1];
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(a[i] & a[j],mx);
			}
				
		}
		cout<<mx;
	}
	else{
		sort(a+1,a+n+1,cmp);
		while(mx==0){
			mx=a[x++];
			for(int i=x;i<=x+m-2;i++){
				mx=mx & a[i];
			}
		}
		cout<<mx;
	}
	return 0;
} 
