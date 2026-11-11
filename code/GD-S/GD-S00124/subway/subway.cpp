#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long wi[500050];
int line[550][10000100];
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>wi[i];
	} 
	for(int i=0;i<n;i++){
		int ki=0;
		cin>>ki;
		for(int j=0;j<2*ki;j++){
			cin>>line[i][j];
		}
	}
	for(int I=0;I<q;I++){
		int x,y;
		int where_x,where_y;
		int time=0;
		cin>>x>>y;
		for(int i=0;i<n;i++){
			for(int j=0;j<d;j+=2){
				if(line[i][j]==x) where_x=i*10+j;
				if(line[i][j]==y) where_y=i*10+j;
			}
		}
		if(where_x/10==where_y/10){
			time=wi[x-1]+line[where_x/10][where_x%10+1]+line[where_y/10][where_y%10+1]+wi[y];
		}
		else{
			int x_y=0;
			for(int i=0;i<d;i+=2){
				for(int j=0;j<d;j+=2){
					if(line[where_x/10][i]==line[where_y/10][j]){
						time=wi[x]+line[where_x/10][where_x%10+1]+ line[where_x/10][i+1] +line[where_y/10][j+1] +line[where_y/10][where_y%10+1]+wi[y];
					}
				}
			}
		}
	}
	cout<<time;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
