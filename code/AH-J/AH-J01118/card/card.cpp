#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int flag[N],cnt[N];
int ccnt[N],last[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if (n<=5000){
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++){
			stack<int>st;
			int id=i;
			while(id<=n){
				if (flag[a[id]]==i){
					while(st.top()!=a[id]){
						flag[st.top()]=0;
						st.pop();
					}
				}else{
					flag[a[id]]=i;
					st.push(a[id]);
				}
				id++;
			}
			for(int j=1;j<=m;j++)
				if (flag[j]==i)
					cnt[j]++;
		}
		for(int i=1;i<=m;i++)
			cout<<cnt[i]<<" ";
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
			last[a[i]]=i;
		}
		for(int i=1;i<=m;i++)
			cout<<last[i]<<" ";
	}
	return 0;
}
