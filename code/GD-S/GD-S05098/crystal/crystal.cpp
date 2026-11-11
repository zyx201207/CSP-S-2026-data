#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m;
int n;
ll a[500010];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		int temp=1;
		int rest=m;
		while(a[i-1]==a[i]&&i-1>0){
			temp++;
			i--;
		}
		for(int j=i-1;j>0;j--){
			if(a[j]+rest>=a[i]){
				temp++;
				rest-=a[i]-a[j];
			}
			else break;
		}
		ans=max(ans,temp);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
