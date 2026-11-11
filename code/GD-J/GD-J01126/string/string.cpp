#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn = 2e5+5;
struct node{
	char c;
	long long num;
	bool vis = false;
}d[maxn];
int n;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> d[i].num >> d[i].c;
	}
	int i=1,j=n;
	int ans = 0; 
	while(i < j){
		if(d[i].c == d[j].c){
			int can = min(d[i].num,d[j].num);
			d[i].num -= can;
			d[j].num -= can;
			if(d[i].num == 0) d[i].vis = true,i++;
			if(d[j].num == 0) d[j].vis = true,j--;
		}
		else{
		int can = min(d[i].num,d[j].num);
			d[i].num -= can;
			d[j].num -= can;
			ans += can;
			if(d[i].num == 0) d[i].vis = true,i++;
			if(d[j].num == 0) d[j].vis = true,j--;
		}
	}
	cout << ans;
	return 0;
}

