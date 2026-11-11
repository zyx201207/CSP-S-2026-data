#include<bits/stdc++.h>
using namespace std;
char y[200005];
long long n,ans,x[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> x[i] >> y[i];
	int l = 1,r = n;
	while(l < r){
		long long tmp = min(x[l],x[r]);
		if(y[l] != y[r]) ans += tmp;
		if(tmp == x[l] && tmp == x[r]){l++;r--;
		}else if(tmp == x[l]){l++;x[r] -= tmp;
		}else{r--;x[l] -= tmp;}
	}
	cout<<ans;
	return 0;
} 
