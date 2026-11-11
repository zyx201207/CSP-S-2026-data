#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m,a[200050];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		
		cin>>a[i];
		
	}
	
	sort(a,a+n,cmp);
	
	int ans=a[0];
	
	for(int i=0;i<n-1;i++){
		
		if( a[i] == a[i+1] ){
			
			a[i] = 0 ;
			
		}
		
	}
	
	sort(a,a+n,cmp);
	
	for(int i=0;i<m;i++){
		
		ans &= a[i];
		
	}
	
	cout<<ans;
	
	return 0;
}