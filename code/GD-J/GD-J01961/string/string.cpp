#include<bits/stdc++.h>
using namespace std;
int n;
struct Node{
	int num;
	char ch;
}node[200005];
int cnt=0;
long long ans=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		char r;
		cin>>r;
		if(node[i-1].ch!=r){
			node[++cnt].num=t;
			node[cnt].ch=r;
		}else{
			node[i-1].num+=t;
		}
	}
	int p=0;
	int x=n-p;
	while(x!=p){
		if(node[p].ch!=node[x].ch){
			ans+=min(node[p].num,node[x].num);
			if(max(node[p].num,node[x].num)==node[p].num){
				node[p].num-=node[x].num;
				x--;
			}else{
				node[x].num-=node[p].num;
				p++;
			}
		}else{
			if(max(node[p].num,node[x].num)==node[p].num){
				node[p].num-=node[x].num;
				x--;
			}else{
				node[x].num-=node[p].num;
				p++;
			}
		}
	}
	cout<<ans;
	return 0;
}
