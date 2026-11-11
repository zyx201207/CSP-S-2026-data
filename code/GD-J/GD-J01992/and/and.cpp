#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],d,ans;
vector<int> lst,cur; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int len=log2(a[i]);
		d=max(d,len);
		lst.push_back(a[i]);
	}
	for(int i=d;i>=0;i--){
		int c=0;
		for(int j:lst){
			if(j&(1<<i)) c++;
		}
		if(c>=m){
			ans+=(1<<i);
			cur=lst;
			lst.clear();
			for(int j:cur){
				if(j&(1<<i)) lst.push_back(j);
			}
		}
	}
	cout<<ans;
	return 0;
}

