#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int x,sum,ans,maxx;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int w=a[1];
	
	for(int i=1;i<=n;i++){
		ans=a[i]; 
		for(int j=i+1;j<=m+i-1;j++){
			ans=ans&a[j];
		}
		maxx=max(maxx,ans);
		if(a[m+i-1]>=a[m+i-2]*8) break;
	}
	cout<<maxx;
	return 0;
} 


