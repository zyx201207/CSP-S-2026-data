#include<bits/stdc++.h>
using namespace std;
struct node{
	bool vis=0;
	int ans;
}v[300005];
vector<int> a;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(v[x].vis==1){
			while(a.back()!=x){
				v[a.back()].vis=0;
				a.pop_back();
			}
			a.pop_back();
		}
		v[x].vis=1;
		a.push_back(x);
		for(int y:a){
			v[y].ans++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<v[i].ans<<' ';
	}
	return 0;
}
