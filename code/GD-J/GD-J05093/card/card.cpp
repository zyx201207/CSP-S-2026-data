#include<bits/stdc++.h>
using namespace std;
stack<int> stk1,stk2;
int n,m,x;
int cnt[500003],a[500003];//a for a, cnt for ans
bool flag=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			flag=0;
			while(!stk1.empty()){
				if(stk1.top()!=a[j]){
					stk2.push(stk1.top());
					stk1.pop();
				}
				else{
					flag=1;
					break;
				}
			}
			while(!stk2.empty()){
				stk1.push(stk2.top());
				stk2.pop();
			}
			if(flag){
				while(stk1.top()!=a[j]){
					stk1.pop();
				}
				stk1.pop();
				stk1.push(a[j]);
				continue;
			}
			else{
				stk1.push(a[j]);
			}
		}
		while(!stk1.empty()){
			cnt[stk1.top()]++;
			stk1.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
