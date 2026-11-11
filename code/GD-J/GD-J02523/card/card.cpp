#include<bits/stdc++.h>
using namespace std;
int a[500005];
struct {
	vector<int> d;
	int cnt;
}b[300005];
int main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	int m,n;cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]].d.push_back(i);
		b[a[i]].cnt++;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i].cnt!=1){
				j=b[i].d[b[i].cnt];
								
			}
		}
		
	}
	return 0; 
}
