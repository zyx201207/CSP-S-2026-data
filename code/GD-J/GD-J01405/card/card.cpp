#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int a[N],v[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	set<int> s;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s.insert(a[i]);
	for(int i=1;i<=n;i++){
		stack<int> x;
		map<int,int> mp;
		for(int j=i;j<=n;j++){
			if(mp[a[j]]!=0){
				while(!x.empty()){
					int w=x.top();
					x.pop();
					mp[w]--;
					if(w==a[j])break;
				}
				x.push(a[j]);
				mp[a[j]]++;
			}else{
				x.push(a[j]);
				mp[a[j]]++;
			}
		}
		while(!x.empty()){
			int w=x.top();
			v[w]++;
			x.pop();
		}
	}
	for(auto i:s){
		cout<<v[i]<<" ";
	}
	return 0;
} 
