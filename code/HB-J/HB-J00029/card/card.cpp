#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[500010],cnt[300010];
bool book[300010],flagA=true;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]<arr[i-1]) flagA = false;
	}
	if(flagA){
		for(int i=1;i<=n;i++) cnt[arr[i]]++;
		long long ans;
		for(int i=1;i<=m;i++){
			ans += cnt[i];
			cout<<ans-1<<" ";
		}
		return 0;
	}
	for(int k=1;k<=n;k++){
		stack<int> s;
		memset(book,0,sizeof(book));
		for(int i=k;i<=n;i++){
			if(!book[arr[i]]){
				book[arr[i]] = true;
				s.push(arr[i]);
			}
			else{
				while(s.top()!=arr[i]){
					book[s.top()] = false;
					s.pop();
				}
			}
		}
		for(int i=1;i<=m;i++) cnt[i] += book[i];
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}
