#include<bits/stdc++.h>
using namespace std;
int n,m,q[200010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}sort(q+1,q+1+n,cmp);
	int ans;
	for(int i=1;i<=m;i++){
		q[i+1]=q[i]&q[i+1];
	}cout<<q[m];
	return 0;
} 
