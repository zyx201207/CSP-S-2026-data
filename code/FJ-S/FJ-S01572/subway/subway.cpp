#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[50005],k[508],a[508][50005],t[508][50005],x,y,ans;
int b[500008];
void f(int l,int step,int ti){
	//cout<<l<<' '<<step<<' '<<ti<<endl; 
	if(step>=k[l]){
		return;
	} 
	if(b[a[l][step]]==1||b[a[l][step]]==3){
		return;
	}
	if(b[a[l][step]]>=2){
		b[a[l][step]]=3;
	}
	else{
		b[a[l][step]]=1;
	}
	if(a[l][step]==y){
		ti+=t[l][step];
		ans=min(ans,ti);
		return;
	}
	f(l,step+1,ti);
	for(int i=0;i<n;i++){
		if(i==l){
			continue;
		}
		for(int j=0;j<k[i];j++){
			if(a[i][j]==a[l][step]&&b[a[i][j]]!=3){
				b[a[i][j]]=2;
				f(i,j,ti+t[l][step]+t[i][j]);
				b[a[i][j]]=0; 
			}
		}
	}
	b[a[l][step]]=0;
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		ans=2100000000;
		cin>>x>>y;
		for(int i=0;i<n;i++){
			for(int j=0;j<k[i];j++){
				b[a[i][j]]=0;
			} 
		} 
		for(int i=0;i<n;i++){
			for(int j=0;j<k[i];j++){
				if(a[i][j]==x){
					f(i,0,t[i][j]);
					
				}
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
} 
