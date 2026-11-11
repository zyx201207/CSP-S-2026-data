#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[500010];
int k;
int sub[500010];

struct node{
	int gt,tm;
};
vector <node> mp[510]; 

int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>sub[j*2-1]>>sub[j*2];
			if(j>1){
				mp[sub[j*2-3]].push_back()
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	}
}

