#include<bits/stdc++.h>
using namespace std;
bool cnt(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	//cin>>n>>m;
	scanf("%d%d",&n,&m);
	int a[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==n-1){sort(a+1,a+1+n,cnt);int ans=a[1];
		for(int i=2;i<=m;i++)ans=ans&a[i];
		a[1]=ans;
	}
else{

for(int i=1;i<m;i++){
	for(int j=1;j<=n;j++){int ans=0;
		for(int k=j+1;k<=n;k++){
		
			ans=max(a[j]&a[k],ans);
		}a[j]=ans;
	}sort(a+1,a+1+n,cnt);
}}
cout<<a[1];
	return 0;
}
