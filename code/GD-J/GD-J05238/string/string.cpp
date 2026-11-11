#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
#define int long long
int n,a[N],ans;char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	} 
	for(int l = 0,r = n+1,lst = 0,rst = 0; l <= r;){
		if((lst==0||rst==0)&&r-l<=1)break;
		if(lst==0)l++,lst=a[l];
		if(rst==0)r--,rst=a[r];
		if(c[l]==c[r]){
			int x=min(lst,rst);
			lst-=x;rst-=x;
		}
		else{
			int x=min(lst,rst);
			lst-=x;rst-=x;
			ans+=x;
		}
	}
	cout << ans;
	return 0;
} 
