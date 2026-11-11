#include<bits/stdc++.h>
#define ll long long
#define kesln(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
int n,a[5555],m,mx=-1e9;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	kesln(i,1,n)cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<n;i++){
		int t=m,cnt=1;
		for(int j=i+1;j<=n;j++){
			if(t>=a[i]-a[j]){
				t-=(a[i]-a[j]);	
				cnt++;
			}else{
				break;
			}
		}
		mx=max(cnt,mx);
	}
	cout<<mx;
	return 0;
}

