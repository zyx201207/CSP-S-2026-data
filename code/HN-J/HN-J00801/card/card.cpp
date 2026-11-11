#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n,m;
int a[1000000];
deque<int> q;
int num[1000000];
int ans[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(num[a[j]]!=0){
				while(num[a[j]]){
					num[a[q.back()]]--;
					q.pop_back();
				}
			}
			q.push_back(j);
			num[a[j]]++;
		}
		while(q.size()){
			q.pop_back();
		}
		for(int j=1;j<=m;j++){
			if(num[j]!=0){
				ans[j]++;
			}
			num[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
