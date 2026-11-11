#include<bits/stdc++.h>
using namespace std;
long long n,m,p[50005],l,r,ans[50005],z[50005];
long long a,b,c;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		ans[i]=0;
	}
	for(int j=0;j<=50000;j++){
		ans[j]=0;
	}
	for(int i=1;i<=n;i++){
		/*for(int j=0;j<=50000;j++){
			z[j]=0;
		}*/
		l=1;
		r=1;
		z[r]=p[i];
		for(int j=i+1;j<=n;j++){
			a=0;
			for(int k=l;k<=r;k++){
				if(z[k]==p[j]){
					a=k;
					break;
				}
			}
			if(a){
				r=a-1;
			}
			r++;
			z[r]=p[j];
		}
		for(int j=l;j<=r;j++){
			ans[z[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
