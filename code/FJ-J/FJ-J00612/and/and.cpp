#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m; 
long long a[N],an;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=m;i++){
		a[i]=a[i]&a[i-1];
	}
	cout<<a[m];
	
	
	return 0;
}





//9:25
//ÂÒÐ´ing 






