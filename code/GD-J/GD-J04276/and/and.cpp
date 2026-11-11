#include<bits/stdc++.h>
using namespace std;
#define ll long long
void fo(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	return;
}
void sol(){
	int n,m,t,ans=0;
	bool a[200001][31]={},x[200001]={},f=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t,x[i]=1;
		for(int j=1;t;j++)
			a[i][j]=t%2,t/=2;
	}
	for(int i=30;i>0;i--){
		t=0,ans=ans*2;
		for(int j=1;j<=n;j++)
			if(a[j][i]&&(f==0||(f&&x[j])))t++;
		if(t>=m){
			for(int j=1;j<=n;j++)
				if(!a[j][i])x[j]=0;
			f=1;
			ans++;
		}
	}
	cout<<ans; 
	return;
}
int main(){
	fo();
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		sol();
	}
	return 0;
}
