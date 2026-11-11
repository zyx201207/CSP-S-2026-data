#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k[30000000],w[1000000000],a,b,s[60000000],st[6000000],gp=1;
long long t,lk[1000000][1000000];
struct ok{
	long long number;
	long long time;
	long long train;
}l[100000][100000];
void op(long long g,long long h){
	s[h]=g;
}
void find(long long f){
	if(s[f]==f){
		return ;
	}else{
		find(s[f]);
		st[gp]=s[f];
		gp++;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		s[i]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>l[i][j].number >>l[i][j].time ;
			if(l[i][j].train !=0){
				lk[l[i][j].number ][i-1]=i-1;
				lk[l[i][j].number ][i]=i;
			}else{
			       l[i][j].train =i;				
		    } 
			if(j>=2){
				op(l[i][j-1].number ,l[i][j].number );
			}
		}
	}
	int h;
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		gp=1;
		find(b);
		t=t+w[a]+w[b];
		for(int j=1;j<=gp;j++){
			if(st[gp]==a){
				h=gp;
			}
		}
		st[0]=1;
		t=t+l[l[a][a].train ][l[a][a].number ].time ;
		for(int j=1;j<=h;j++){
			t+=l[l[st[j-1]][st[j]].train ][l[st[j-1]][st[j]].number ].time ;
		}
		t+=l[l[st[h]][l[k[n]][b].train ].number ][l[st[h]][l[k[n]][b].train ].train ].time ;
		cout<<t; 
	}
	return 0;
}
