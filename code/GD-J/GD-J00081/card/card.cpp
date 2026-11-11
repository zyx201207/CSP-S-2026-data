#include <bits/stdc++.h>
using namespace std;

int l[550000] = {},c[300001] = {};
bool fk[300001] = {};
stack <int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);	
	for(int i = 0;i < n;i ++){
		scanf("%d",&l[i]);
		fk[l[i]] = 1;
	}
	int k = 0;
	while(k <= n){
		bool f[300001] = {};
		while(!s.empty()){
			c[s.top()] ++;
			s.pop();
		}
		for(int i = k;i < n;i ++){
			if(f[l[i]] != 1){
				s.push(l[i]);
			}
			else{
				while(f[l[i]] && !s.empty()){
					f[s.top()] = 0;
					s.pop();
				}
				s.push(l[i]);
			}
			f[l[i]] = 1;
		}
		k ++;
	}
	for(int i = 0;i < 300001;i ++){
		if(fk[i]) printf("%d ",c[i]);
	}
	return 0;
}

