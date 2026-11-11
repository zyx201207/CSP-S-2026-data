#include<bits/stdc++.h>
using namespace std;
int a[200010];
long long ans;
bool cmp(int x,int y){
	return x>y;
}
int f[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
   
   int n,m;
   long long minn=1e9+10;
    cin>>n>>m;
   for(int i=1;i<=n;i++){
	   cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
	
	
	for(int i=1;i<=m;i++){
		minn=a[m];
	
}
cout<<minn;
    return 0;
}
