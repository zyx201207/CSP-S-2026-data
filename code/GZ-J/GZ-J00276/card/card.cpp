//GZ-J00276 »ÆÈË÷ë 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans[N];
vector<int> tabel;
int find(int x){
	for(int i:tabel) if(i==x) return 1;
	return -1; 
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		tabel.clear();
		for(int j=i;j<=n;j++){
			int k=find(a[j]);
//			cout<<k<<"\n";
			if(k==-1) tabel.push_back(a[j]);
			else{
				while(*(tabel.rbegin())!=a[j]) tabel.pop_back();
				tabel.pop_back();
				tabel.push_back(a[j]); 
			}
		}
		for(int j=1;j<=m;j++) if(find(j)!=-1) ans[j]++;
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
