//GZ-J00242 北京师范大学贵阳附属中学 李培源
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],b[N],f[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i; 
	}
	for(int j=1;j<=n;j++){
		int i=j;
		while(i<=n){
			if(b[a[i]]!=i){
				i=b[a[i]];
			}
			else{
				f[a[i]]++;
				i++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<' '; 
	}
	return 0;
} 
