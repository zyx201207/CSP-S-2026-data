#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("r","hub.in",stdin);
	freopen("w","hub.out",stdout);
	int c,t;
	cin >> c >> t;
	for (int i=1;i<=t;i++){
		int n,k;
		int x=1;
		for (int j=1;j<n;j++){
			cin >> u >> v;
			if (a[u]==a[v]){
				if (a[u]==0)
				{
					a[u]=x;
					a[v]=x;
					x++;
				}
			}
			else
			{
				if (a[u]==0)a[u]=a[v];
				else if (a[v]==0)a[v]=a[u];
				else {
					for (int ii=1;ii<=j;ii++){
						if (a[ii]==a[v] && ii!=v){
							a[ii]=a[u];
						}
					}
					a[v]=a[u];
				}        
			}           
		}                   
		int mas=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]==a[i+1])mas++; 
		}
		cout << mas << endl;
	}
	return 0;
}
