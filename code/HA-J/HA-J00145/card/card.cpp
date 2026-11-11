#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[500005];
int ans[300005];
bool f[300005];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[arr[j]]){
				while(!s.empty()){
					if(s.top()==arr[j]){
						break;
					}
					f[s.top()]=false;
					s.pop();
				}
			}
			else{
				s.push(arr[j]);
				f[arr[j]]=true;
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			f[s.top()]=false;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
