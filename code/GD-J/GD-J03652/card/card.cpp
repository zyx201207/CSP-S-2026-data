#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],v[500005],c[500005],mm;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mm = max(mm,a[i]);
	}
	for(int i=1;i<=m;i++){
		queue <int> q;
		for(int j=i;j<=n;j++){
			if(b[a[j]]>0){
				for(int k=0;k<=q.size();k++){
					q.pop();
				}
				for(int k=1;k<=n;k++){
					b[a[k]] = 0;
				}
			}
			q.push(a[j]);
			b[a[j]]++;
			c[a[j]] = j;
		}
		for(int j=0;j<q.size();j++){
			v[q.front()]++;
			q.pop();
		}
		for(int k=i;k<=n;k++){
			b[a[k]] = 0;
		}
	}
	for(int i=1;i<=n;i++){
		if(v[a[i]]!=0) cout<<v[a[i]]<<' ';
	}
}

