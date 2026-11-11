#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,l,o=0,p=0;
	cin>>n>>m;
	int a[100]={};
	int d[100]={};
	int s[100][100]={};
	int g[100][100]={};
	int z[100]={};
	int w[100]={};
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int y=a[i];
		l=0;
		while(y>0){
			y/=2;
			l++;
		}
		d[i]=l;
		while(l>=0){
			s[i][l]=a[i]%2;
			a[i]/=2;
			l--;
		}
	}
	for(int i=1;i<=n;i++){
		o++;
		w[i]=d[i];
		for(int j=1;j<=m;j++){
			if(s[i][d[i]]==s[i+o][d[i]]&&s[i+o][d[i]]!=0){
				p++;
				g[p][d[i]]=1;
				d[i]--;
			}else{
				p++;
				g[p][d[i]]=0;
				d[i]--;
			}
		}
	}
	for(int i=1;i<n;i++){
		z[i]+=g[i][w[i]];
		for(int j=w[i];j>=1;j--){
			for(int k=i;k>=1;){
				z[i]+=g[i][j]*2;
				k--;
				cout<<j<<endl<<z[i]<<endl<<endl;
			}
		}
	}
	sort(z,z+n);
	cout<<z[n-2];
	return 0;
}
