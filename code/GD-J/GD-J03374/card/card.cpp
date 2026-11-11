#include <bits/stdc++.h>
using namespace std;
int n,m;
stack<int> s;
int a[500005],b[300005],c[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];

	}


	for(int i = 1;i <= n;i++){
		
		for(int j = i;j <= n;j++){
			s.push(a[j]);
			b[a[j]]++;
			if(b[a[j]] == 2){
				s.pop();
				while(1){
					if(s.top() == a[j]){
						b[s.top()] = 1;
						break;
					}else{
						b[s.top()] = 0;
						s.pop();
					}
				} 
			}
			
		}
		while(!s.empty()){
			c[s.top()]++;
			b[s.top()] = 0;
			s.pop();
		}
	}
	for(int i = 1;i <= m;i++){
		cout << c[i] <<" ";
	}
	return 0;
}
