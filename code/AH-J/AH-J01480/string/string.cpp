#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=2e5+1e1;
struct node{
	int num;
	char c;
} nodes[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int num=0;
    for(int i=1;i<=n;i++){
		cin>>nodes[i].num>>nodes[i].c;
		num+=nodes[i].num;
	}
	int l=1,r=n,cnt=0;
	while(l<=r){
		if(nodes[l].num==nodes[r].num){
			if(nodes[l].c==nodes[r].c){
				l++,r--;
			} else {
				l++,r--;
				cnt+=nodes[l-1].num;
			}
			nodes[l-1].num=0,nodes[r+1].num=0;
		} else if(nodes[l].num<nodes[r].num){
			if(nodes[l].c==nodes[r].c){
				l++;
				nodes[r].num-=nodes[l-1].num;
				nodes[l-1].num=0;
			} else {
				l++;
				nodes[r].num-=nodes[l-1].num;
				cnt+=nodes[l-1].num;
				nodes[l-1].num=0;
			}
		} else {
			if(nodes[l].c==nodes[r].c){
				r--;
				nodes[l].num-=nodes[r+1].num;
			} else {
				r--;
				nodes[l].num-=nodes[r+1].num;
				cnt+=nodes[r+1].num;
			}
			nodes[r+1].num=0;
		}
	}
	cout<<cnt;
    return 0;
}
