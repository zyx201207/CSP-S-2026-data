#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<int> lst,cur;
	for(int i=1;i<=n;i++)lst.push_back(i);
	int ans=0;
	for(int j=30;~j;j--){
		cur.clear();
		for(int i:lst){
			if(a[i]>>j&1)cur.push_back(i);
		}
		if(cur.size()>=m){
			lst=cur;
			ans|=1<<j;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
