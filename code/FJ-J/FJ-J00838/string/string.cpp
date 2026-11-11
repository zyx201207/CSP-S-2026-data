#include<bits/stdc++.h>
using namespace std;
#define int long long
int z[200005];
char z2[200005];
int n;
int ans=0;
void gj(int i,int j){
	if(i>=j) return;
	if(z2[i]==z2[j]){
		if(z[i]==z[j]) gj(i+1,j-1);
		else if(z[i]>z[j]){
			z[i]-=z[j];
			gj(i,j-1);
		}
		else{
			z[j]-=z[i];
			gj(i+1,j);
		}
	}
	else{
		if(z[i]==z[j]){
			ans+=z[i];
			gj(i+1,j-1);
		}
		else if(z[i]<z[j]){
			ans+=z[i];
			z[j]-=z[i];
			gj(i+1,j);
		}
		else{
			ans+=z[j];
			z[i]-=z[j];
			gj(i,j-1);
		}
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		z[i]=a;
		z2[i]=c;
	}
	gj(1,n);
	cout<<ans;
}
