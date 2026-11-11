#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
bool b[300010];
int ans[500010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int>q;
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				bool temp=0;
				while(temp){
					int x=q.top();
					if(x!=a[j]){
						b[x]=0;
						q.pop();
					}
					else{
						temp=1;
					}
				}
			}
			else{
				b[a[j]]=1;
				q.push(a[j]);
			}
		}
		while(q.size()){
			cout << q.top() << " ";
			ans[q.top()]++;
			q.pop();
		}
		cout << endl;
	}
	for(int i=1;i<=m;i++) cout << ans[i] << " ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

