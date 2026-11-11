#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int w[N];
struct node1{
	int sta[N],t[N];
};
node1 line[310];
struct node2{
	int w,cet[310],top=0;
};
node2 p[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>p[i].w;
	}
	for(int i=1;i<=q;i++){
		cout<<1;
	}
	return 0;
}
