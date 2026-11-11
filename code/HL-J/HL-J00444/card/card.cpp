#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
bool used[2000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	stack<int> sk;
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(used,0,sizeof(used));
		for(int j=i;j<=n;j++){
			sk.push(a[j]);
			if(!used[a[j]]) used[a[j]];
			else{
				while(sk.top()!=a[j]) sk.pop();
			}
		}
		while(!sk.size()){
			if(sk.top==m){
				cout<<sk.top<<" ";
				break;
			}
			else sk.pop();
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
