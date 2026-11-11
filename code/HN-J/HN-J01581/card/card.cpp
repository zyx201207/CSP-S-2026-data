#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[300010],k[500010],l,b[300010];
queue<int> q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;l=n;
	for(int i=1;i<=n;i++) cin>>k[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			a[k[j]]++;
			if(a[k[j]]>1) a[k[j]]=0,a[k[j-1]]--,q.pop();
			else q.push(a[k[j]]);
			int l=1;
			while(!q.empty()){
				if(a[q.top()]!=0&&l) b[a[k]]++,l=0;
				q.pop();
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i];
	return 0;
 } 
