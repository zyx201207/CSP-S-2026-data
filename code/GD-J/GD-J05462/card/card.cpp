#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int a[N];
struct node{
	bool have;
	int wei;
};
int ans[N];
vector <int> v;
node b[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]].have==0){
				b[a[j]].have=1;
				b[a[j]].wei=v.size();
				v.push_back(a[j]); 
			}
			else{
				for(int k=v.size()-1;k>=b[a[j]].wei+1;k--){
					b[v[k]].have=0;
					b[v[k]].wei=0;
					v.pop_back();
				}
			}
		}
		for(int j=0;j<v.size();j++){
		//	cout<<v[j]<<" ";
			b[v[j]].have=0;
			b[v[j]].wei=0;
			ans[v[j]]++;
		}
	//	cout<<'\n';
		v.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	
}
/*

4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1






*/
 
