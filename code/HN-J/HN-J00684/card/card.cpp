#include<bits/stdc++.h>
using namespace std;
int n,m,a[500086],g[300086],cut[300086];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		queue<int>k,l;
		for(int j=i;j<=n;j++){
			if(!g[a[j]]){
				g[a[j]]=1;
				k.push(a[j]);
			}else{
				int d=0,o=0;
				while(!k.empty()){
					if(k.front()==a[j])o=1;
					if(!o)l.push(k.front());
					k.pop();
				}while(!l.empty()){
					k.push(l.front());
					l.pop();
				}k.push(a[j]);
			}
		}while(!k.empty()){
				cut[k.front()]++;
				k.pop();
			}
	}for(int i=1;i<=m;i++){
		cout<<cut[i]<<" ";
	}return 0;
}
