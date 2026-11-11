#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int p;
	char c;
}a[200000+25];
bool cmp(node x,node y){
	return x.c < y.c;
}
signed main()
{	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i].p>>a[i].c;
	}
	//sort(a+1,a+n+1,cmp);
	int l = 1,r = n;
	int cnt = 0;
	while(l <= r){
		if (l == r) break;
		if (a[l].c != a[r].c){
			if (a[l].p > a[r].p){
				a[l].p -= a[r].p;
				cnt += a[r].p; 
				r--;
			}
			else if (a[l].p < a[r].p){
				a[r].p -= a[l].p;
				cnt += a[l].p;
				l++;
			}
			else{
				cnt += a[l].p;
				l++;
				r--;
			}
		}
		else if (a[l].c == a[r].c && a[l].p != a[r].p){
			if (a[l].p > a[r].p){
				a[l].p -= a[r].p;
				r--;
			}
			else{
				a[r].p -= a[l].p;
				l++;
			}
		}
		else{
			l--;
			r++;
		}
	}
	cout<<cnt<<"\n";
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
