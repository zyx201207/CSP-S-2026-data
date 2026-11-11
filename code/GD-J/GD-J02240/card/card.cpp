#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
const int N = 500005;
int a[N], n, m, tot, d[N];
bool b[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in", "r", stdin);
		freopen("card.out", "w", stdout);
		cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	for(int i=1; i<=n; i++){
		for(int k=1; k<=m; k++) b[k]=0;
		//cout<<'f';
		stack <int> q;
		for(int k=1; k<m; k++) b[k] = 0;
		for(int j=i; j<=n; j++){
			//cout<<'z';
			//cout<<'h'<<b[3]<<'h';
			//cout<<a[j];
			//if(!q.empty())
			//cout<<q.top()<<' ';
			if(b[a[j]]){
				while(q.top() != a[j]){
					b[q.top()] = 0;
					q.pop();
					//cout<<'>';
;				}
			}
			else{
				q.push(a[j]);
				b[a[j]]++;
			}
		//	cout<<'\n';
			for(int k=1; k<=m; k++){
		//	cout<< b[k];
			}
			
			
		
		}
		for(int k=1; k<=m; k++){
						d[k] += b[k];
			}
			//for(int k=1; k<=m; k++){
		//	cout<< d[k];
		//	}
	}
//	cout<<'g';
	for(int i=1; i<=m; i++)
			cout<<d[i]<<' ';
	return 0;
}
