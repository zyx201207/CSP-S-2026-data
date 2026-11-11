#include <bits/stdc++.h>
using namespace std;
int n,m;
int maxx,c,w;
int a[1000006];
deque<int>dq;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	a[0]=a[1];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		w+=c*(a[i]-a[i-1]);
		c++;
		dq.push_back(a[i]);
		while(w>m){
			w-=a[i]-dq.front();
			c--;
			dq.pop_front();
		}
		maxx=max(maxx,c);
	}
	cout<<maxx;
	return 0;
}
/*
5 5
1 2 4 8 9

*/

