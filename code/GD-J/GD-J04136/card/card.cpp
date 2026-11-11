#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],ans[1005],t[1005],p[1005],cnt=1,vis[1005],sum=1,y[1005];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
for(int i=1;i<=n;i++){
	for(int j=i;j<=n;j++){
		int flag=0;
		if(vis[a[j]]==0){
		if(t[a[j]]==0){
			p[++cnt]=a[j];
			t[a[j]]=1;
		}else{
			t[a[j]]=1;
			for(int k=i;k<=j;k++){
				if(flag==1){
					//vis[p[k]]==1;
					p[k]=0;
					t[p[k]]=0;
				}
				if(p[k]==a[j]){
					//vis[p[k]]==1;
					p[k]=0;
					flag=1;
				}
			}
			p[++cnt]=a[j];
		}
	}
	}
	for(int j=1;j<=cnt;j++){
		//cout<<p[j]<<' ';
		y[p[j]]++;
	}
	for(int j=i;j<=n;j++){
		vis[j]=0;
		t[j]=0;
		p[j]=0;
		y[j]=0;
	}

}
for(int i=1;i<=m;i++){
cout<<y[i]<<' ';
}
	return 0;
}

