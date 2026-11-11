#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,m;
int a[N],sum[N];
bool b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=m;j++) b[j]=0;
		for(int j=i;j<=n;j++){
			
			if(b[a[j]]==1){
				for(int x=i;x<=j-1;x++) b[x]=0;
			}
			b[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(b[j]==1){
				sum[j]++;
			}
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<' ';
	return 0;
}
 
