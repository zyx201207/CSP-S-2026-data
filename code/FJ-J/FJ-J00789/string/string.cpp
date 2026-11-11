#include<bits/stdc++.h>
using namespace std;
long long n,a[200024],ans;
char b[200024];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int z=1,y=n;
	while(z<=y){
		if(a[z]>a[y]){
			if(b[z]!=b[y]){
				ans+=a[y];
			}a[z]-=a[y];
			y--;
			
		}else if(a[z]<a[y]){
			if(b[z]!=b[y]){
				ans+=a[z];
			}a[y]-=a[z];
			z++;
			
		}else{
			if(b[z]!=b[y]){
				ans+=a[y];
			}z++;
			y--;
		}
		
	}
	cout<<ans;
}
