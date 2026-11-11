#include<bits/stdc++.h>
using namespace std;
long long a[1000000];	
long long pre[1000000];
long long yigong[1000000];
long long n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long maxn = -1e9;
	int j = 0;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++){
    	pre[i] = pre[i-1]+(a[i]-a[i-1])*(i-j-1);
		yigong[i] = yigong[i-1]+1;
		while(pre[i]>m){
	        j++;
			pre[i]-=(a[i]-a[j]);
			yigong[i]-=1;
		}
		maxn = max(yigong[i],maxn);
	}
	cout<<maxn;
	return 0;
}
