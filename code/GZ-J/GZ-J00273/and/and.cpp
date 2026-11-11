//GZ-J00273 樊辰熙
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
string ss[N];
int main(){
	freopen("and.in","r",stdout);
	freopen("and.out","w",stdin);
	int n,m;cin >> n >> m;
	int mx=0;
	for(int i=0;i<n;i++){
		 int x;
		 cin >> x;
		 mx=max(mx,x);
	}
	cout << mx;
}
