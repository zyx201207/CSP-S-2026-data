#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[5005],f[5005][5005];
int ff(int k,int e){int s=0;
	if(k>e)return 0;
	if(k==e)return 1;
	if(f[k][e]!=-1)return f[k][e];
	int h=k+1;
	while(h<=e){
		if(a[h]-a[k]<=d){s+=ff(h,e);}h++;
	}
	//cout<<k<<" "<<e<<" "<<s<<endl;
	return f[k][e]=s;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){memset(f,-1,sizeof(f));
		int s=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i+1<n;i++)for(int j=i+2;j<=n;j++){
			if(ff(i,j)==3)s++;
		}
		cout<<s<<"\n";
	}
	return 0;
}
