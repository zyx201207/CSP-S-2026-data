#include<bits/stdc++.h>
using namespace std;
long long n,m,a[700000],w[700000],d,q,s,m1,p[700000],x,y;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>n;
	for(int i=0;i<n;i++){
		s=0;
		cin>>m1>>m;
		long long sl;
		for(int j=0;j<m1;j++){
			cin>>a[j];
			if(j==0)sl=a[0];
			a[j]-=sl;
		}
		for(int ks=0;ks<m1;ks++){
			memset(p,0,sizeof(p));
			memset(w,0,sizeof(w));
			w[ks]=1;
			for(int j=ks;j<m1;j++){
				for(int k=j+1;k<m1;k++){
					if(a[k]-a[j]>m)break;
					if(p[k]==0){
						p[k]=p[j]+1;
					}
					if(p[k]==p[j]+1){
						w[k]++;
					}
				}
			}
			for(int j=ks;j<m1;j++){
				if(w[j]>0)s+=w[j]-1;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
