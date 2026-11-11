#include<bits/stdc++.h>
using namespace std;
struct node{
	int be,ed;
};

vector<node>nodes;
void func(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int b,e;
		cin>>b>>e;
		node r={b,e};
		nodes.push_back(r);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		func();
	}
	return 0;
}
