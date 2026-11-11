#include<bits/stdc++.h>
#define ll long long
#define int long long
#define endl '\n'
using namespace std;
const int N = 200005;
int a[N];
char c[N];
ll sum;
struct node{
	int l,r;
	int siz;
	char op;
}id[N];
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i]>>c[i];
		id[i].l = sum+1;
		id[i].r = sum+a[i];
		id[i].op = c[i];
		id[i].siz = a[i];
		sum += a[i];
	}
//	for(int i = 1; i <= n; i++){
//		cout<<id[i].siz<<" ";
//	}
	int ltid = 0;
	int rtid = n+1;
	int lnow = 0;
	int rnow = sum+1;
	while(1){
		int tot = 0;
		int sam = 0;
		int num = 0;
		ltid++;
		lnow += id[ltid].siz;
		lnow = min(sum/2, lnow);
//		cout<<lnow<<" ";
		rtid--;
		num = rnow-id[rtid].siz;
//		cout<<num<<endl;
//		cout<<sum-num+1<<" ";
		while(sum-num+1 < lnow){
			rnow = num;
			tot+=id[rtid].siz;
			if(id[rtid].op == id[ltid].op){
//				cout<<id[rtid].op<<" "<<id[ltid].op<<endl;
				sam += id[rtid].siz;
			}
			rtid--;
			num = rnow-id[rtid].siz;
			cout<<num<<" "<<rnow<<endl;
//			cout<<tot<<" "<<sam<<endl;
		}
		int l1 = sum-lnow+1;
		tot += rnow - l1;
//		cout<<tot<<" "<<sam<<endl;
		if(id[rtid].op == id[ltid].op){
			sam += tot;
		}
//		cout<<tot<<" "<<sam<<endl;
		ans += tot-sam;
//		cout<<ans<<endl;
		if(lnow == sum/2){
			break;
		}
	}
	cout<<ans;
	
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
