#include <bits/stdc++.h>
using namespace std;
int a[500010],k[300010];
map<int,int> m,l;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,u;
	cin>>n>>u;
	for(int p=1;p<=n;p++) cin>>a[p];
	for(int p=1;p<=n;p++){
		m.clear();l.clear();
		int t=1;
		for(int g=p;g<=n;g++){
			if(m[a[g]]){
				for(int h=m[a[g]]+1;h<=t;h++) m[l[h]]=0;
				t=m[a[g]]+1;
			} 
			else{
				m[a[g]]=t;l[t]=a[g];t++;
			}
		}
		for(int x=1;x<=u;x++){
			if(m[x]==0||!m[x]) continue;
			k[x]++;
		}
	}
	for(int p=1;p<=u;p++) cout<<k[p]<<' ';
	return 0;
}
