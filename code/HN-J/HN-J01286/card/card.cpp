#include<bits/stdc++.h>
using namespace std;

stack <int> s;
int a[30005];
int b[30005];
int y[30005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for (int j=i;j<=n;j++){
			s.push(a[j]);
			b[a[j]]++;
			if (b[a[j]] == 2){
				b[a[j]]=1;
				int ok=1;
				while (ok && !s.empty()){
					s.pop();
					if (s.top() == a[j]){
						ok=0;
					}
				}
			}
		}
		while (!s.empty()){
			y[s.top()]++;
			s.pop();
		}
	}
	for (int i=1;i<=m;i++){
		cout<<y[i]<<" ";
	}
	return 0;
} 
