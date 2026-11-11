#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],st=30,ans;
vector<int> v;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v.push_back(i);
	}
	while(v.size()>=m){
		vector<int> e[35];
		for(int p:v){
			for(int i=0;i<=30;i++){
				if(a[p]&(1<<i)){
					e[i].push_back(p);
				}
			}
		}
		bool flag=1;
		for(int i=st-1;i>=0;i--){
			if(e[i].size()>=m){
				flag=0;
				st=i;
				ans+=pow(2,i);
				break;
			}
		}
		if(flag){
			break;
		}
		v.clear();
		for(int p:e[st]){
			v.push_back(p);
		}
	}
	cout<<ans;
	return 0;
}
/*
5 3
31 3 1 15 7
*/
