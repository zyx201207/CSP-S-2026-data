//GZ-J00049 贵阳市第一中学 吴昊然 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,t[M],d[M],a[N];
void tj(int x){
	if(x>n){
		return;
	}
	if(d[a[x]]==x){
		t[a[x]]++;
		tj(x+1);
		return;
	}else{
		tj(d[a[x]]);
		return;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(d[a[i]]==0){
			d[a[i]]=i;
		}
	}
	for(int i=n;i>=1;i--){
		tj(i);
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
