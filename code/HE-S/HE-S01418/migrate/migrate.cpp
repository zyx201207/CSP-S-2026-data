#include<bits/stdc++.h>
using namespace std;
int c,s=0,tt;
bool t[5005][5005];
long long a[200005];
void f(int i,int j){
	if(i==j){
		s++;
		return ;
	}
	for(int k=i+1;k<=j;k++){
		if(t[i][k]){
			f(k,j);
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>tt;
	while(tt--){
		memset(t,false,sizeof(t));
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i]; 
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]<=a[i]+d) t[i][j]=true;
				else break;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				s=0;
				f(i,j);
				if(s==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
}

