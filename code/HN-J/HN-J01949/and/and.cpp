#include<iostream>
#include<algorithm>
using namespace std;
int n,m,ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n],b[n][35],c[n],d[n][35],e[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		int j=0;
		while(a[i]!=0){
			b[i][j]=a[i]%2;
			a[i]/=2;
		}
		c[i]=j+1;
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(c[i]>=c[j]){
					for(int x=0;x<c[i];x++){
						d[ans][x]=b[i][x]*b[j][x];
						e[ans]+=d[ans][x]*2;
					} 
				}else {
					for(int x=0;x<c[j];x++){
						d[ans][x]=b[i][x]*b[j][x];
						e[ans]+=d[ans][x]*2;
					} 
				}
				ans++;
			}
		}
	}
	sort(e,e+ans);
	for(int i=0;i<ans;i++){
		cout<<e[i]<<" ";
	}
	return 0;
} 
