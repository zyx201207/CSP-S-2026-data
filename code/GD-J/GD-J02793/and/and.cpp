#include<bits/stdc++.h>
using namespace std;
//int two(int x){
//	int s[100005];
//	string z;
//	int j=0,p=0;
//	while(x/2!=0){
//		j++;
//		s[j]=x%2;
//		x/=2; 
//	}
//	for(int i=j;i>=1;i--){
//		p++;
//		z[p]=s[i];
//	}
//	int(p);
	 
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100005];

	for(int i=1;i<=n;i++){
		cin>>a[i];
//		b[i]=two(a);
		
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			
			int w=a[i]&a[j];
			if(w>ans){
				ans=w;
			}
		}
	}
	cout<<ans;
	
	return 0;
} 
