//GZ-S00241,娄芷淇,贵阳市第一中学
#include<bits/stdc++.h>
using namespace std;
int stanum[100005],sta[100005][100005],t[100005][100005],line,c,n,m,d,q,k,w[100005],start[100005],end[100005];
int panduan(int a,int b){
	for(int i=1;i<=n;i++){
		if(sta[i][a]==a){
			for(int j=1;j<=n;j++){
				if(sta[j][b]==b){
					if(i==j){
						line=i;
						return 1;
					}
				}
			} 
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	cin>>n;
	cin>>m;
	cin>>d;
	cin>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		int stacnt=0;
		cin>>stanum[i];
		for(int j=1;j<=2*stanum[i];j++){
			if(j%2==1){
				cin>>k;
				sta[i][k]=k;
			}
			if(j%2==0){
				cin>>t[sta[i][k]][i];
				k=0;
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>start[i]>>end[i];
	}
	for(int i=1;i<=q;i++){
		if(panduan(start[i],end[i])==1){
			cout<<w[start[i]]+t[start[i]][line]+t[end[i]][line]+w[end[i]]<<endl;
		}
	}
	return 0;
}
