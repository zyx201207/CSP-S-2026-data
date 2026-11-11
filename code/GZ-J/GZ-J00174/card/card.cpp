//GZ-J00174 ºúî£³¿
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010];
stack <int> st;
struct node{
	bool vis=0;
	long long sum=0;
}f[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if (!f[a[j]].vis){
				st.push(a[j]);
				f[a[j]].sum++;
				f[a[j]].vis=1;
			}
			else{
				while(st.top()!=a[j]){
					f[st.top()].vis=0;
					f[st.top()].sum--;
					st.pop();
				}
			}
		}
		while(!st.empty()) st.pop();
		for (int j=1;j<=m;j++) f[j].vis=0;
	}
	for (int i=1;i<=m;i++) cout<<f[i].sum<<' ';
	return 0;
}
