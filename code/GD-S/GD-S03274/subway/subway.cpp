#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],minnn=1e9,X;
int a[505][20005],t[505][20005],P[505][20005];
bool b[500005];
void dd(int xx,int yy,int num){
	if(xx==yy){
		minnn=min(minnn,num);
		return;
	}
	if(b[xx]) return;
	int B=0;
	for(int i=1;i<=n;i++){
		if(a[i][xx]){
			if(xx==X){
				num+=t[i][xx];
			}
			else if(B!=0){
				num+=t[i][xx];
			}
			b[xx]=true;
			dd(a[i][xx],yy,num+t[i][a[i][xx]]);
			b[xx]=false;
			if(xx==X){
				num-=t[i][xx];
			}
			else if(B!=0){
				num-=t[i][xx];
			}
			B=i;
		}
	}
	
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int A[500005],T[500005];
		for(int j=1;j<=k;j++){
			cin>>A[j]>>T[j];
		}
		for(int j=1;j<k;j++){
			a[i][A[j]]=A[j+1];
			t[i][A[j]]=T[j];
		}
		t[i][A[k]]=T[k];
	}
	for(int i=1;i<=q;i++){
		int x,y;
		minnn=1e9;
		cin>>x>>y;
		X=x;
		dd(x,y,w[x]);
		cout<<minnn+w[y]<<'\n';
	}
	return 0;
}
