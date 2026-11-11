#include<bits/stdc++.h>
using namespace std;
const int LEN=5e5+10;
int n,m;
int a[LEN];
int cnt[int(5e5+10)];
bool find(stack<int> s,int x){
	while(!s.empty()){
		if(s.top()==x)return 1;
		s.pop();
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> s;
		for(int j=i;j<=n;j++){
			if(!find(s,a[j])){
				s.push(a[j]);
			}
			else{
				while(!s.empty()&&s.top()!=a[j]){
					s.pop();
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(find(s,j)){
				cnt[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
} 
