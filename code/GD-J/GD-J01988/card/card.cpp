#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
int a[500008];
int sum[500008];
vector<int> q; 
void check(int st,int size_){
	if(st==0){
		q.clear();		
		return;
	}
	for(int i=st;i<=size_;i++)
		q.pop_back();
}
void solve(int st){
	q.clear();
	for(int i=st;i<=n;i++){
		if(q.empty()){
			q.push_back(a[i]);
			continue;
		}
		bool flag=1;
		for(int k=0;k<q.size();k++){
			if(q[k]==a[i]){
				check(k,q.size()-1);
				flag=0;
				q.push_back(a[i]);
				break;
			}
		}
		if(flag)
			q.push_back(a[i]);
	}
	for(int i=0;i<q.size();i++)
		sum[q[i]]++;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	

	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		solve(i);
	for(int i=1;i<=m;i++)
		cout<<sum[i]<<' ';
	return 0;
}
