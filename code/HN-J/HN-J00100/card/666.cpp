#include<bits/stdc++.h>
using namespace std;
long long n,m,qp,ans,a[10000000],jl[1000000],bc[1000000],jz[1000000],cd,zj;

int f(int to,int to1,int qd){
	if(a[to]>zj||bc[to1]>zj)return 0;
	if(jl[to]!=jz[to1]){
		int x=a[to]-qd;
		int y=bc[to1]-qd;
		ans+=min(x,y);
		if(x>y){
			f(to,to1+1,bc[to1]);
		}
		if(x=y)f(to+1,to1+1,bc[to1]);
		if(x<y)f(to+1,to1,bc[to]);
	}
	else {
		int x=a[to]-qd;
		int y=bc[to1]-qd;
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
	cin>>n;int wz=1;
	for(int i=1;i<=n;i++){
		int zjz;char c;
		cin>>zjz>>c;
		jl[i]=c-'a'+1;
		cd+=zjz;
		a[i]=a[i-1]+zjz;
	}	int jsq=1;
 zj=cd/2;
 if(cd%2==1)zj+=1;
	for(int i=n;i>=n/2;i--){	
		if(bc[i]>=zj){bc[i]=zj;break;
			//bc[jsq]=cd/2-bc[jsq-1];
		};
		bc[jsq]=bc[jsq-1]+a[i]-a[i-1];jz[jsq]=jl[i];
		jsq++;		
	} 	for(int i=1;i<=n;i++){	if(a[i]>=zj){//cout<<a[i]<<" ";
			a[i]=zj;break;
		}
		//if(a[i>cd/2+1&&cd%2==1])a[i]=cd/2+1;
	}
	//for(int i=1;i<=jsq;i++)cout<<jl[1]<<endl; 
		//for(int i=1;i<=jsq;i++)cout<<jz[1]<<endl;
	//	cout<<cd/2;	
	f(1,1,0);
	cout<<ans;
	
	
	
	
	
	
	
	
	return 0;	
}
