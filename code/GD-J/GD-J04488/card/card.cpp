#include<bits/stdc++.h>
using namespace std;
long long n,m,num[300005],a[500005];
struct nl{
	bool tr=true;
	int pos;
}pv[500005];
void cmb(int x,int y){
	for(int i=x;i<y;i++){
		pv[a[i]].tr=true,pv[a[i]].pos=-1;
	}
}
void lp(){
	for(int i=1;i<=m;i++){
		if(pv[i].tr==false){
			num[i]++;
			pv[i].tr=true;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(num,0,sizeof num);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!pv[a[j]].tr){
				cmb(pv[a[j]].pos,j);
			}
			pv[a[j]].tr=false,pv[a[j]].pos=j;
		}
		lp();
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
