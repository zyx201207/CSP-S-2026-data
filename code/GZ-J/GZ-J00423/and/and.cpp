//GZ-J00423 兴义市弘毅中学 王富俊
#include<bits/stdc++.h>
using namespace std;
long long m,n,f,d,ans;
long long a[200050];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	ans=0;
	for(int i=1;i<=(1<<n);i++){
		f=0;d=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				if(f==0){
					d=a[j];
				}
				else{
					d=d&a[j];
				}
				f++;
			}
		}
		if(f==m){
			ans=max(ans,d);
		}
	}
	
	cout<<ans;
	
	return 0;
} 
 
