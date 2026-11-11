#include <bits/stdc++.h>
using namespace std;
int n,m,a_maxn=0;
int b[200050];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			a_maxn=max(a_maxn,b[i]);
		}
		cout<<a_maxn;
		return 0;
	}
	if(m==n){
		a_maxn=b[1];
		for(int i=2;i<=n;i++){
			a_maxn=a_maxn&b[i];
		}
		cout<<a_maxn;
	}
	return 0;
}
