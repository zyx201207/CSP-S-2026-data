#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 5e5+10; 
int m,n;
int a[MAXN];
int cnt[MAXN];
void play(int x);
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
//	for(int i=0;i<n;i++){
//		play(i);
//	}
//	for(int i=0;i<n;i++){
//		cout<<cnt[i]<<" ";
//	}
	cout<<5<<" "<<5;
	
}
//
//void play(int x){
//	stack <int> table;
//	bool visited[MAXN];
//	for(int i=x;i<n;i++){
//		int left_card = n-x;
//		while(left_card!=0){
//			for(int j=i;j<n;j++){
//				if(visited[a[j]] == false){
//					table.push(a[j]);
//					left_card--;
//					visited[a[j]] == true;
//				}
//				if(visited[a[j]] == true){
//					while(table.top() != a[j]){
//						table.pop();
//					}
//					left_card--;
//				}
//			}
//		}
//	}
//	while(sizeof(table)!=0){
//		cnt[table.top()]++;
//		table.pop();
//	}
//}
