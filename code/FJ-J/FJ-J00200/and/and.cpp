#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1,a[200010],x,s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	x=1;
	if(m==2){
		for(int i=x;i<n;i++){
			for(int j=x+1;j<=n;j++){
				s=a[i];
				s&=a[j];
				ans=max(ans,s);
			}
			x++;
		}
	}else if(m==3){
		for(int i=x;i<n-1;i++){
			for(int j=x+1;j<n;j++){
				for(int k=x+2;k<=n;k++){
					s=a[i];
					s&=a[j];
					s&=a[k];
					ans=max(ans,s);
				}
			}
			x++;
		}
	}
	cout<<ans;
	//:|
	return 0;
} 
