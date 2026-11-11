#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<endl; 
	int ans=a[n-1];
	for(int i=n-2;i>=0;i--){
		m--;
		if(m==0){
			break;
		}
		ans&=a[i];
	}
	cout<<ans;
	return 0;
} 
