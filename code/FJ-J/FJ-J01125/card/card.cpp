#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5,M=3*1e5+5;
int n,m,a[N],jump[N],ha[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		jump[i]=ha[a[i]];
		ha[a[i]]=i;
	}
	memset(ha,0,sizeof(ha));
	for(int i=0;i<n;i++){
		int x=i+1;
		while(x<=n){
			if(jump[x]==0){
				ha[a[x]]++;
				x++;
			}else{
				x=jump[x];
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ha[i]<<" ";
	}
	return 0;
}