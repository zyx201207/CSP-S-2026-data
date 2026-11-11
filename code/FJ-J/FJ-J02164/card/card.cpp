#include<bits/stdc++.h>
using namespace std;
//unsigned const struct  (vector pueue stack ) push pop empty / pow abs sqrt /reverse unqine
//scanf printf %.3f %lf %d
//fixed setpreicion
int a[500005];
int f[500005];
int g[500005];
int k[500005];
int pp[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ll=1;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(f[a[i]]==0){
			f[a[i]]=1;
			g[ll] = a[i];
			ll++;
		}
	} 
	for(int i = 1;i<=n;i++){
		stack<int> t;
		fill(k,k+5001,0);
		for(int j =i;j<=n;j++){
			if(k[a[j]]>=1){
				while(true){
					k[t.top()]=0;
					pp[t.top()]--;
					if(t.top()==a[j]){
						t.pop();
						break;
					}else{
						t.pop();	
					}

				}

			}
			t.push(a[j]);
			pp[t.top()]++;
			k[a[j]]++;
		}
	} 
	for(int i =1;i<=m;i++){
		cout<<pp[i]<<" ";
	}
	return 0;
} 
