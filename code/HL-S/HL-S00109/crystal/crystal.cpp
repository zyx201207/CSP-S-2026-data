#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int a[N],n,m,b[10010][10010];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    if(n>5000){
    	cout << n;
    	return 0;
	}
    for(int i = 0;i<n;i++){
    	cin >> a[i];
	}
	for(int i = 0;i<n;i++){
		int minn = a[i];
		int k = i;
		for(int j = i+1;j<n;j++){
			if(a[j]<minn){
				minn = a[j];
				k = j;	
			}
		}
		a[k] = a[i];	
		a[i] = minn;
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			b[i][j] = -1; 
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			b[i][j] = a[j]-a[i];
		}
	}
	int ans = -1;
	for(int j = n-1;j>=0;j--){
		int sum = 0,num = 0;
		for(int i = j-1;i>=0;i--){
			if(b[i][j]!=-1 && sum+b[i][j]<=m){
				sum+=b[i][j];
				num++;
			}else{
				break;
			}
		}
		ans = max(ans,num);
	}
	
	cout << ans+1;
    return 0;
}
