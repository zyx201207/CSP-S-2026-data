#include<bits/stdc++.h>
using namespace std;
struct BL{
	int t,n;
	BL* l;
	BL* r;
};
int L(int p[10][10],int n,int end){
	int ans;
	for(int i=0;i<n;i++){
		if(p[n][end]!=0) return p[n][end];
		if(p[n][i]!=0)ans+=L(p,i,end);
	}
	return ans;
}
int main(){
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int> w;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		w.push_back(a);
	}
	vector<BL*> station;
	int lenth[100][100];
	BL* t;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		int u=0,v,t;
		for(int j=1;j<=k;j++){
			cin>>v>>t;
			lenth[u][v]=t;
			u=v;
		}
	}
	for(int i=1;i<=q;i++){
		int start,end;
		cin>>start>>end;
		cout<<L(p[10][10],start,end);
	}
	return 0; 
}
