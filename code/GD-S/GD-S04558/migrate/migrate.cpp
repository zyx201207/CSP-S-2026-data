#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,a[1000005];
int N(int x,int y){
	if(y>=4&&x==1){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int s=0;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i;j<=n;j++){
				if(N(a[i],a[j])){
					s++;
				}
			}
		}
		cout<<s<<endl;
	}
	
	return 0;
}
