#include<bits/stdc++.h>
using namespace std;
long long qwe[500005];
long long ans[500005]={0}; 
queue<long long>s;
bool bol [500005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n;
	long long m;
	cin >> n>> m;
	for(int i=1;i<=n;i++){
		cin >> qwe[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			bol [j] = 0;
		}
		while(s.size()!= -1){
			s.pop();
		}
		for(int j=i;j<=n;j++){
			s.push(qwe[j]);
			if(bol[qwe[j]]== 1){
				while(s.size()!=1){
					bol[s.front()] = 0;
					s.pop();
				}	
			}
			bol[qwe[j]]=true;
		}
		for(int j=1;j<=m;j++){
			if(bol[j] == 1){
				ans[j] ++ ;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
}
