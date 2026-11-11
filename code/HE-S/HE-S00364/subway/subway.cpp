#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long w[10000],k[10000],a[10000][10000],t[10000][10000],x[10000],y[10000];
int main(){
	long time[10000],time1[10000];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];time[i]=0;
	}
	for(int i=1;i<=q;i++){
	    int s=0,s1,tm=1;
		for(int j=1;j<=n;j++){
			for(int c=1;c<=k[j];c++){
				if(a[j][c]=x[i]){
					s=j;s1=c;
				}
			}
		}
		int r=0,r1;
		for(int j=1;j<=n;j++){
			for(int c=1;c<=k[j];c++){
				if(a[j][c]=y[i]){
					r=j;r1=c;
				}
			}
		}
		if(s==r){
			time[i]=w[x[i]]+t[x[i]][y[i]]+t[x[i]][x[i]]+w[y[i]];
		}else{
			for(int j=1;j<=k[s];j++){
			    for(int c=1;c<=k[r];c++){
				    if(a[s][j]=a[r][j]){
					    time1[tm]=w[x[i]]+t[x[i]][x[i]]+t[x[i]][a[s][j]]+t[a[s][j]][a[s][j]]+t[a[s][j]][y[i]]+w[y[i]];
					    tm++;
				    }
		 	    }
		    }
		}
		if(s!=r){
			int max=0;
			for(int j=1;j<tm;j++){
				if(time1[j]>max){
					max=time1[j];
				}
			}
			time[i]=max;
		}
	}
	for(int i=1;i<=q;i++){
		if(i!=q){
			cout<<time[i]<<endl;
		}else{
			cout<<time[i];
		}
	}
	return 0;
}
