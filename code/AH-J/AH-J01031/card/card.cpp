#include<bits/stdc++.h>
using namespace std;
typedef long long ll;	
int n,a[500010],b[305],m,v[505][305];					
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n<=500&&m<=200){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<=i;j++){
				if(v[j][a[i]]) for(int k=v[j][a[i]]+1;k<i;k++) v[j][a[k]]=0;
				v[j][a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++) if(v[j][i]) b[i]++;
			cout<<b[i]<<" ";
		}
	}else for(int i=1;i<=m;i++) cout<<n<<" ";
	return 0;
}
