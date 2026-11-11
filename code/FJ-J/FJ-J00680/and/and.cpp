#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+5;
struct node{
	int val;
	int num;
	bool operator<(const node&other)const{
		if(num==other.num)return val>other.val;
		return num>other.num;
	}
}a[N];
int n,m;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].val;
		int cnt=0;
		int tmp=a[i].val;
		while(tmp){
			tmp&=(tmp-1);
			cnt++;
		}
		a[i].num=cnt;
	}
	sort(a+1,a+1+n);
	int ans=a[1].val;
	for(int i=2;i<=m;i++){
		ans&=a[i].val;
	}
	cout<<ans<<endl;
	return 0;
}
