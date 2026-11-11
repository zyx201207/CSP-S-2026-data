#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int MAXN=200005;
int a[MAXN];
bool px(int x,int y){
	return x>y;
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);	
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int m,n;
cin>>n>>m;
for(int i=0;i<n;i++){
	cin>>a[i];
}
sort(a,a+n,px);
int ans=0;
for(int k=0;k<n;k++){
	for(int i=k;i<n-1;i++){
		int p=a[k];
		for(int j=2;j<=m;j++){
			p=a[i+j-1]&p;
		}
		ans=max(ans,p);
	}
}
cout<<ans;
	return 0;
}
