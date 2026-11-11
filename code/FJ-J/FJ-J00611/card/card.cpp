#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],p[200005];
bool b[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>p[i];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(b[p[j]]==1){
				for(int x=j-1;;x--){
					b[p[x]]=0;
					if(p[x]==p[j]) break;
				}
			} b[p[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(b[j]==1){
				b[j]=0;
				a[j]++;
			}
		} 
	} for(int j=1;j<=m;j++){
		cout<<a[j]<<" ";
	} 
	return 0;
} 
