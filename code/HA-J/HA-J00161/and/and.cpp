#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,TKP=32;
typedef long long ll;
//想一想，为什么？
int n,m,arr[N],cf[N][TKP],siz;
queue<int> qe;
int pfs(int pyi){
	int afs=1;
	for(int i=1;i<=pyi;i++) afs*=2;
	return afs;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	siz=n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		qe.push(i);
		int op=arr[i],p=0;
		while(op>0){
			cf[i][++p]=op-((op>>1)<<1);
			op=op>>1;
		}
	}
	int ans=0;
	for(int i=31;i>=1;i--){
		int col=0;
		for(int j=1;j<=siz;j++){
			int plft=qe.front();
			qe.push(qe.front());
			qe.pop();
			if(cf[plft][i]==1) col++;
		}
		if(col>=m){
			ans+=pfs(i-1);
			int nsiz=siz;
			for(int j=1;j<=siz;j++){
				if(cf[qe.front()][i]==0){
					qe.pop();
					nsiz--;
				}
				else{
					qe.push(qe.front());
					qe.pop();
				}
			}
			siz=nsiz;
		}
	}
	cout<<ans;
	return 0;
}
