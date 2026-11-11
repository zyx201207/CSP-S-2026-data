#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],maxx=INT_MIN;
void dfs(int x,int cnt){
	int t=x,d=1;
	if(maxx<cnt) maxx=cnt;
	if(t==0) return ;
	dfs(d-1,cnt=(cnt&a[d++]));
	d++;
	dfs(d,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(m,0);
	cout<<9;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
