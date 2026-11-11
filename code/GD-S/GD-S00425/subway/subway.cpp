#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in",'l',stdin);
	freopen("subway.out",'r',stdout);
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	int n[c];
	for(int i=0;i<c;++i)cin>>n[i];
	int m[b],m1[b][9999999],m2[b][9999999];
	for(int i=0;i<b;++i){
		cin>>m[i];
		for(int j=0;j<m[b];++j){
			cin>>m1[i][j]>>m2[i][j];
		}
	}
	while(e--){
		int x,y;
		cin>>x>>y;
		int xi,xj,yi,yj;
		for(int i=0;i<b;i++){
			for(int j=0;j<m[i];j++){
				if(m1[i][j]==x){
					xi=i,xj=j;
					break;
				}
			}
		}
		for(int i=0;i<b;i++){
			for(int j=0;j<m[i];j++){
				if(m1[i][j]==y){
					yi=i,yj=j;
					break;
				}
			}
		}
		int js=n[x]+m2[xi][xj]+m2[yi][yj]+n[y];
		cout<<js<<endl;
	}
	fclose("subway.in");
	fclose("subway.out");
}
