#include <bits/stdc++.h>
using namespace std;
const int N=5e3+5;
char a[N];
string s[N];
int dist[N]={0};
void dick(string cnt){
	int x[N]={0};
	int j=1;
	queue<int> q;
	q.push(cnt[0]-'0');
	x[cnt[0]-'0']++;
	while(j<cnt.size()){
		x[cnt[j]-'0']++;
		if(x[cnt[j]-'0']%2==0){
			int d[N]={0};
			int mqz=1;
			bool qaz=true;
			while(!q.empty()){
				if(q.front()==cnt[j]-'0'){
					qaz=false;
					q.pop();
				}
				if(qaz){
					d[mqz]=q.front();
					mqz++;
				}
				q.pop();
			}
			for(int k=1; k<mqz; k++){
				q.push(d[k]);
			}
		}
		q.push(cnt[j]-'0');
		j++;
	}
	bool vis[N]={0};
	while(!q.empty()){
		if(!vis[q.front()]){
			dist[q.front()]++;
		}
		vis[q.front()]=true;
		q.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	int sum=1;
	string ans="";
	for(int i=n; i>=1; i--){
		ans +=a[i];
		int x=ans.size();
		string wsx=ans;
		for(int j=0; j<x; j++){
			wsx[j]=ans[x-j-1];
		}
		s[sum]=wsx;
		sum++;
	}
	for(int i=1; i<sum; i++){
		string cnt=s[i];
		dick(cnt);
	}
	for(int i=1; i<=m; i++){
		cout << dist[i] <<" ";
	}
	return 0;
}
