#include<bits/stdc++.h>
using namespace std;
int a[500005],b[10000][10000],c[10005][10005],n;
int d[500005];
int dz(int s,int e){
	if(s==e){
		return 0;
	}int t=1000000000000;
	for(int i=1;i<=n;i++){
		if(d[i]==0&&c[s][i]!=0){
			d[i]=1;
			t=min(t,dz(i,e)+c[s][i]);
			d[i]=0;
		}
	}
	if(t==0){
		return 0;
	}else{
		return t;
	}
}
int main(){
	int c,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int in[k],nt[k];
		for(int j=1;j<=k;i++){
			cin>>in[j]>>nt[j];
			if(j>1){
				for(int l=1;l<j;l++){
					if(c[in[j]][in[j-l]]==0){
						c[in[j]][in[j-l]]=nt[j]+nt[j-l];
						c[in[j-l]][in[j]]=nt[j]+nt[j-l];
					}else{
						c[in[j]][in[j-l]]=min(c[in[j]][in[j-l]],nt[j]+nt[j-l]);
						c[in[j-l]][in[j]]=c[in[j]][in[j-l]];
					}
				}
			}
		}
		for(int j=1;i<=m;i++){
			d[i]=0;
		}
		for(int j=1;i<=q;i++){
			int s,e,t=0;
			cin>>s>>e;
			d[s]=1;
			t=min(t,dz(s,e));
			cout<<a[s]+a[e]+t<<endl;
		}
	}
	
}
