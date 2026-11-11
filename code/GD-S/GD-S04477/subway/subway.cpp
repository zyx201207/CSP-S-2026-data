#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct subway{
	int x;
	int y[510];//վ 
	int z[510];//վ̨
};
void sta(int x,int y,int z,bool ji[]){
	if(x==y){
		cout<<z;
		return;
	}
	sta(x+1,y,z,ji);
}
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	subway line[100010];
	for(int i=0;i<m;i++){
		cin>>line[i].x;
	}
	for(int i=0;i<n;i++){
		int s;
		cin>>s;
		cout<<s;
		for(int j=0;j<s;j++){
			int v;
			cin>>v;
			line[v].y[n]=1;
			cin>>line[v].z[n];
		}
	}
	return 0;
}
