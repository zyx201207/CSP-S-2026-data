#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[20010],b[20010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		int ans=a[i],mth=0;
		while(ans>0){
			if(mth==0)
				b[i]=b[i]+ans%2;
			else
				b[i]=b[i]+ans%2*mth*10;
			mth++; 
			ans=ans/2;
		}
	}
	sort(b+1,b+n+1);
	int z1=0;
	for(int i=1;i<=n;i++){
		int mth=m;
		int mat=1;
		string x=string(b[i]);
			int z=0;
			for(int l=mat;l<=mat+mth;l++){
				string y=string(b[l]);
				for(int j=0;j<min(b[i);j++){
					if(x[j]=='1'&&y[j]=='1'&&j!=0)
						z+=1*j*10;
					else if(x[j]=='1'&&y[j]=='1')
					z+=1;
				}
				z1=max(z,z1);
			}
		}
	
	int ans=0,vis=1;
	while(z1>0){
		ans+=z1%10*vis;
		vis=vis*2; 
		z1=z1/10;
	}
	cout<<vis;
	
	return 0;
}
