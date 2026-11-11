#include<bits/stdc++.h>
using namespace std;
long long n,m,qp,ans,a[1000000],jl[1000000],bc[1000000],jz[1000000],cd;

int f(int to,int to1,int qd){
	if(a[to]>=cd/2||bc[to1]>=cd/2)return 0;
	if(jl[to]!=jz[to1]){
		int x=a[to]-a[to-1]-qd;
		int y=bc[to1]-bc[to1-1]-qd;
		ans+=min(x,y);
		if(x>y){
			f(to,to1+1,bc[to1]);
		}
		if(x=y)f(to+1,to1+1,bc[to1]);
		if(x<y)f(to+1,to1,bc[to]);
	}
	else {
		int x=a[to]-a[to-1]-qd;
		int y=bc[to1]-bc[to1-1]-qd;
		ans+=abs(x-y);
		if(x>y){
			f(to,to1+1,bc[to1]);
		}
		if(x=y)f(to+1,to1+1,bc[to1]);
		if(x<y)f(to+1,to1,bc[to]);
	}
	
}
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		jl[i]=c-'a'+1;cd+=a[i];a[i]=a[i-1]+a[i];
	}
	
	
	int jsq=1;

	for(int i=n;i>=n/2;i--){
		
		if(a[i]<=cd/2){
			bc[jsq]=cd/2-bc[jsq-1];
		};
		bc[jsq]=bc[jsq-1]+a[i]-a[i-1];jz[jsq]=jl[i];
		jsq++;		
	} 
	f(1,1,1);
	
	
	
	
	
	cout<<ans;
	




	return 0;
	
	
	
}
