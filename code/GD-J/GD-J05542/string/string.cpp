#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct node{
	int x;
	char c;
}a[300001];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i].x >> a[i].c;
	}
	int i = 1,j = n;
	int ans = 0;
	for(;i<=j;){
		if(a[i].x < a[j].x){
			if(a[i].c != a[j].c) ans+=a[i].x;
			a[j].x-=a[i].x;
			i++;
		}else if(a[i].x > a[j].x){
			if(a[i].c != a[j].c) ans+=a[j].x;
			a[i].x-=a[j].x;
			j--;
		}else{
			if(a[i].c != a[j].c) ans+=a[i].x;
			i++,j--;
		}
	}
	cout << ans;
	return 0;
}
