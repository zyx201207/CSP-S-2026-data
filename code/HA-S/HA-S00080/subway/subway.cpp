#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int startt,endd,jl;
int minn=1e8,maxx=-1e8;
int w[2010],a[2010][2010],t[2010][2010];
void oop(int x,int y,int timee,int nm){
	if(x==y){
		timee=timee+w[startt]+w[endd]+jl;
		minn=min(minn,timee);
		return;
	}
	if(x==m){
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=maxx;j++){
			if(a[i][j]==x&&a[i][j+1]!=0){
				if(x==startt) jl=t[i][j];
				if(i!=nm){
					oop(a[i][j+1],y,timee+t[nm][j]+t[i][j],i);
				}
				else{
					oop(a[i][j+1],y,timee,i);
				}
				break;
			}
			else if(a[i][j]==0){
				break;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		maxx=max(maxx,k);
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		
		cin>>startt>>endd;
		oop(startt,endd,0,0);
		cout<<minn<<endl;
		minn=1e8;
	}
	return 0;
}
