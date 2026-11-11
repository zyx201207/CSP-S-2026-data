#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int a[N];
int cnt[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	int top=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		stack<int> s;
		map<int,int> mp;
		for(int j=i;j<=n;j++)
		{
			if(mp[a[j]])
			{
				top--;
				while(top>mp[a[j]]){
					mp[s.top()]=0;
					s.pop();
					top--;
				}
				mp[a[j]]=top;
				top++;
			}
			else
			{
				s.push(a[j]);
				mp[a[j]]=top++;
			}
		}
		while(!s.empty()){
			cnt[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" "; 
	return 0;
}
