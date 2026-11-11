#include <bits/stdc++.h>
using namespace std;
vector <int> vt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int lt;cin>>lt;
	if(m==1){
		for(int i=1;i<n;i++){
			int t;cin>>t;
			lt=max(lt,t);
		}
	}
	if(n==m){
		for(int i=1;i<n;i++){
			int t;cin>>t;
			lt&=t;
		}
	}
	cout<<lt;
	return 0;
}
