#include<bits/stdc++.h>
using namespace std;

int a[500005];
int cnt[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	queue<int> q;
	for(int i=0;i<n;i++){
		int b[300005]={0};
		for(int j=i;j<n;j++){
			b[a[j]]++;
			if(b[a[j]] % 2 == 0){
				while(!q.empty()){
					q.pop();
				}
			}
			q.push(a[j]);
		}
		while(!q.empty()){
			int d=q.front();
			q.pop();
			cnt[d]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << cnt[i] << ' ';
	}
	return 0;
}
