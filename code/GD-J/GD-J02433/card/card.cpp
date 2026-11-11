#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int a[500010],ne[500010],id[300010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i++){
		cin>>a[i];
		if (id[a[i]]) ne[id[a[i]]] = i;
		id[a[i]] = i;
	}
	for (int i = 1;i <= n;i++){
		int j = i;
		while (ne[j]) j = ne[j];
		while (j <= n){
			ans[a[j]]++;
			while (ne[j]) j = ne[j];
			j++;
		}
	}	
	for (int i = 1;i <= m;i++)
		cout<<ans[i]<<" ";
	return 0;
} 
