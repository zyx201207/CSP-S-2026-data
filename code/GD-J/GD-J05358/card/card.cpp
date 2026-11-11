#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],u[5005][3005],p[5005],l,s[5005],h;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)scanf("%d",&a[i]);
	for(int i=1; i<=n; i++){
		l=0;
		for(int j=i; j<=n; j++){
			l++;
			if(p[a[j]]==0){
				u[i][l]=a[j]; p[a[j]]=1;
			}
			else{
				h=a[j];
				l--;
				while(u[i][l]==h){
					p[u[i][l]]=0;
					u[i][l]=0;
					l--;
				}
			}
		}
		for(int j=1; j<=n; j++)if(p[j]==1)s[j]++;
	}
	for(int i=1; i<=n; i++)if(s[i]!=0)cout<<s[i]<<" ";
	return 0;
}
