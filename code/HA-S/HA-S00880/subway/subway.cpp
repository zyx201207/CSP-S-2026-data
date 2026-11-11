#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w1,ai;
const int N=100,M=1000,Q=1000,K=51,D=21;
int w[M],k,a[N][K],t[N][K],x[Q],y[Q],mintime[Q];
int n1,t1;
struct station{
	int line[D];
	int linesum;
	int time[N*K];
}sta[M];
int search(int x,int y){
	int sumin=1e+09;
	bool direct=false;
	for(int i=0;i<sta[x].linesum;i++){
		for(int j=0;j<sta[y].linesum;j++){
			if(sta[x].line[i]==sta[y].line[j]){
				direct=true;
				if(sumin>sta[x].time[sta[x].line[i]]+sta[y].time[sta[y].line[i]])	sumin=sumin>sta[x].time[sta[x].line[i]]+sta[y].time[sta[y].line[i]];
			}	
		}
	}
	if(direct){
		return sumin;
	}
	bool xtrue=false,ytrue=false;
	int x1,y1,zan;
	for(int i=1;i<=m;i++){
		for(int j=0;j<sta[x].linesum;j++){
			for(int z=0;z<sta[i].linesum;z++){
				if(sta[x].line[j]==sta[i].line[z]){
					xtrue=true;		x1=sta[i].line[z];
					for(int c=0;c<sta[y].linesum;c++){
						for(int v=0;v<sta[i].linesum;v++)
						{
							if(sta[y].line[c]==sta[i].line[v]){
								ytrue=true;	y1=sta[i].line[v];
								if(sumin>(sta[i].time[x1]+sta[i].time[y1])){
									sumin=sta[i].time[x1]+sta[i].time[y1];
									zan=i;
								}	
							}
						}
					}
				}
			}
		}
	}
	return sumin+search(x,zan)+search(zan,y); 	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		k=0;
		cin>>k;
		n1=0;t1=0;
		for(int j=1;j<=k;j++)
		{
			cin>>n1;
			sta[n1].line[sta[n1].linesum]=i;
			sta[n1].linesum++;
			cin>>t1;
			sta[n1].time[i]=t1;
		}
	}
	for(w1=1;w1<=q;w1++)
	{
		scanf("%d %d",&x[w1],&y[w1]);
		mintime[w1]=search(x[w1],y[w1])+w[x[w1]]+w[y[w1]];
	}
	for(ai=1;ai<=q;ai++)
	{
		cout<<mintime[ai]<<endl;
	}
	return 0;
}
