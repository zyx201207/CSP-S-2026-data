//GZ-J00187  遵义市新蒲中学 王墨霖 
#include <bits/stdc++.h>
using namespace std;
long long  u[20001];
bool cop(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ma=-1;
	if(m==1){
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			if(a>ma) ma=a;
		}
		cout<<ma;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			cin>>u[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
			 if(u[i]&u[j]>ma) ma=u[i]&u[j];
			}
		}
		cout<<ma;
	}else{
		for(int i=1;i<=n;i++){
			cin>>u[i];
		}
		sort(u+1,u+n+1,cop);
		cout<<u[m];
	}
	return 0;
}

