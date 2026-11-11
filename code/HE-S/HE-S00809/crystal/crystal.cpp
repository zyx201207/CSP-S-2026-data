#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int n,m,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ans=0;
	cin>>n;
	cin>>m;
	while(n--){
		cin>>a[n];
		for(int i=0;i<n;i++){
			int v=a[2]-a[0];
			int e=a[2]+v;
			m=m-v;
			int r=a[2]-a[1];
			int d=a[1]+r;
			m=m-r;
			if(e==a[2]){
				ans=ans+1;
			}if(r==a[2]){
				ans=ans+1;
			if(a[2]==a[i-2]){
				ans+=a[i-2];
			}
		
}
		}
	
	cout<<ans;
		
	return 0;
}
}
