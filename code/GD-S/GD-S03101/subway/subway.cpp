#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,w;
	bool operator<(const node &s)const{
		return s.w<w;
	}
};
const int N=5e5+10;
vector<int>t[N];
int c,n,m,d,q,w[N],k[N];
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)cin>>w[i];
	
	return 0;
} 
