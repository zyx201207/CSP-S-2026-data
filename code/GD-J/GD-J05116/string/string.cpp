#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a[N],z;
char c[N];
deque<int> q;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		q.push_back(a[i]);
	}
	int l=1,r=n;
	while(l<r){
		int x=q.front(),y=q.back();
		q.pop_front();q.pop_back();
		int di=min(x,y);
		if(c[l]!=c[r]) z+=di;
		if(x>y){
			r--;a[l]-=di;
			q.push_front(a[l]);
		}else if(x<y){
			l++;a[r]-=di;
			q.push_back(a[r]);
		}else{
			l++;r--;
		}
	}
	cout<<z;
	return 0;
}
