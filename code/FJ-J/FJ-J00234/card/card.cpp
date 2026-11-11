#include<bits/stdc++.h>

using namespace std;

const int N=5e5+10;

int n,m;
int a[N],st[N];
//vector<int> g;

//void query(int k){
//	if(g.size()){
//		for(int i=0;i<g.size();i++){
//			if(g[i]==k){
//				g.erase(i,g.end());
//				g.push_back(k);
//				break;
//			}
//		}
//	}else{
//		g.push_back(k);
//	}
//}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	bool A=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			A=false;
		}
	}
	
	if(A){
		for(int i=1;i<=n;i++){
			st[a[i]]+=i;
		}
		for(int i=1;i<=m;i++){
			cout<<a[i]<<" ";
		}
	}
	
//	for(int i=1;i<=n;i++){
//		g.clear();
//		for(int j=i;j<=n;j++){
//			query(a[j]);
//		}
//		for(int i=0;i<g.size();i++){
//			st[g[i]]++;
//		}
//	}
//	for(int i=1;i<=m;i++){
//		cout<<st[i]<<" ";
//	}
//	
	return 0;
} 
