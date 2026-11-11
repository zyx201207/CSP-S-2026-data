#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,i,j,k;
	cin>>n>>m;
	vector<int> e(m);
	deque<int> v(n);
	for(i=0;i<n;i++) scanf("%d",&v[i]);
	for(i=0;i<n;i++){
		deque<int> d;
		for(j=i;j<n;j++){
			bool f=0;
			for(k=0;k<d.size();k++){
				if(d[k]==v[j]){
					f=1;
					break;
				}
			}
			if(!f) d.push_back(v[j]);
			else{
				d.erase(d.begin()+k,d.end());
				d.push_back(v[j]);
			} 
		}
		for(j=0;j<d.size();j++) e[d[j]-1]++;
	}
	for(i=0;i<m;i++) printf("%d ",e[i]);
	return 0;
}
