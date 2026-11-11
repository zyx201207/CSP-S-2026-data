#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,a[200005];
int p[300005];
int e[300005];
int game(int r,int y){
	memset(p,0,sizeof(p));
	memset(e,0,sizeof(p));
	for(int i=r;i<=n;i++){
		if(p[a[i]]==1){
			int k=e[a[i]]+1;
			while(e[a[k]]!=e[a[i]]){
				p[a[k]]=0;
				e[a[k]]=0;
				k=k+1;
				//cout<<k<<endl;
			}
		}
		else{
			p[a[i]]=1;
			e[a[i]]=i;
		}
		//cout<<p[1]<<endl;
	}
	/*for(int i=1;i<=m;i++){
		cout<<p[i]<<' ';
	}*/
	//cout<<endl;
	return p[y];
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int y=1;y<=m;y++){
		cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=game(i,y);
		}
		cout<<cnt<<' ';
	}
	return 0;
}
