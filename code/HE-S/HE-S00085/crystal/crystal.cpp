#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Node{
	int index;
	int num;
};
bool f(Node&n1,Node&n2){
	return n1.num<n2.num;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;
	cin>>m;
	vector<int>a(100005,0);
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[x]++;
	}vector<Node>node(n+1);
	int j=1;
	for(int i=1;i<=100005;i++){
		if(a[i]!=0){
			node[j].index=i;
			node[j].num=a[i];
			j++;
		}
	}
	int ans=INT_MIN;
	sort(node.begin()+1,node.end(),f);
	for(int i=j-1;i>0;i--){
		int t1=m;
		int res=node[i].num;
		for(int k=i-1;k>0;k--){
			for(int y=1;y<=node[k].num;y++){
				if(node[i].index-node[k].index<=t1){
					t1-=node[i].index-node[k].index;
					res++;
					if(t1==0){
						break;
					}
				}
			}
		}
		ans=max(ans,res);
		
	}
	cout<<ans<<endl;
	return 0;
}
