#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int truw[N],k[520],roa[N],tim[N],star[N],en[N];
//tru 口到厅 k 经过地铁站数 roa 该线经过的地铁站 tim 走路用时 
int c,n,m,d,q;
int cnt=0;
struct node{
	int roa;
	int tim;
}k[520][N]; 

int main(){
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++) cin>>truw[i];
	for(int i=0;i<n;i++){
		cin>>k[i][0]; //结构体数组中以1为开始值，k[i][0]存站数
		for(int j=0;j<k[i][0];j++) cin>>k[i][j].roa>>k[i][j].tim; 
	}
	for(int i=0;i<r;i++){
		cin>>star[i]>>en[i];
	}
	for(int i=0;i<r;i++){
		cnt=tru[star[i]]+tru[en[i]];
		/*
		if(c>=7 && c<=11){
			
		}
		if(c>=12 && c<=19){
			
		}
		*/
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
