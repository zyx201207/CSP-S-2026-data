#include <bits/stdc++.h>
using namespace std;

int n,m,cnt[300005],a[300005],tmp;
stack<int> s;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int j=1;j<=n;j++){
		bool y[300005]={0};
		for(int i=j;i<=n;i++){
			if(y[a[i]]==0){
				s.push(a[i]);
				y[a[i]]=1;
			}
			else{
				while(!s.empty() ){
					if(s.top()==a[i]){
						break;
					} 
					y[s.top()]=0;
					s.pop();
					
				}
			}
		}
		while(!s.empty()){
			cnt[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout << cnt[i] << " ";
	}
	return 0;
}
