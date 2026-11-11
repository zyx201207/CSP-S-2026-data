#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, m, a[N], pos[N], ans[N];
stack<int> s;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d" ,&n ,&m);
	for(int i = 1;i <= n;i++)
		scanf("%d" ,&a[i]);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++) pos[j] = 0;
		for(int j = i;j <= n;j++){
			if(pos[a[j]]){
				while(s.top() != pos[a[j]]){
					if(pos[a[s.top()]] == s.top()) pos[a[s.top()]] = 0;
					s.pop();
				}
				if(pos[a[s.top()]] == s.top()) pos[a[s.top()]] = 0;
				s.pop();
			}
			s.push(j);
			pos[a[j]] = j;
		}
		while(!s.empty()){
			ans[a[s.top()]]++;
			s.pop();
		}
	}
	for(int i = 1;i <= m;i++)
		printf("%d " ,ans[i]);
	return 0;
}
