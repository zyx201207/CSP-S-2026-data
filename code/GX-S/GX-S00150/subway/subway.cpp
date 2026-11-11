#include <bits/stdc++.h>
using namespace std;
int mo[5000][30];
struct qwe{
    vector <int> ll;
    int zg=0;
};
int s=0;
//void txt(qwe* b,int wz,int zd,int sj){
//	b[wz].zg=1;
//	if (wz==zd){
//		sj+=mo[0];
//	}
//	for (auto x:b[wz].ll){
//		if (b[x].zg==0){
//			
//		}
//	}
//	return ;
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	

	
	
	vector <int> a[n+1];
	for (int i=1;i<=m;i++)
		cin>>mo[i][0];
	for (int i=1;i<=n;i++){
		int k;
		cin>>k;
		for (int j=1;j<=k;j++){
			int u,v;
			cin>>u>>v;
			mo[u][i]=v;
			a[i].push_back(u);
			
		}
	}
	
	
	qwe b[m];
	for (int i=1;i<=n;i++){
		int u=0;
		for (auto x:a[i]){
			if (u==0){
				u=x;
			}
			else{
				b[u].ll.push_back(x);
				b[x].ll.push_back(u);
				u=x;
			}
		}
		
		
	}
	
	for (int i=1;i<=q;i++){
		int u,v;
		s=0;
		cin>>u>>v;
//		txt(b,u,v,0);
        for (int i=1;i<=d;i++){
			if (mo[u][i]>0){
				s+=mo[u][i];
				break;
			}
		}
        for (int i=1;i<=d;i++){
			if (mo[v][i]>0){
				s+=mo[v][i];
				break;
			}
		}
		s+=mo[u][0];
		s+=mo[v][0];
		cout<<s;
		s=0;
	}
	
	return 0;
}
