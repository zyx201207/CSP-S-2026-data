#include<bits/stdc++.h>
using namespace std;
int n,m,mi;
int a[200005],b[200005]; 
int hs(int x,int y){
	int b=1,ans=0;
	while(x>=1&&y>=1){
		int a1=x%2;
		int a2=y%2;
		x/=2;
		y/=2;
		if(a1==1&&a2==1){
			ans+=b;
		}b*=2;
	}return ans;
}bool pd(int a){
	while(a>1){
		int x=a%2;
		if(x==1)return true;
		a/=2;
	}return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int ma=0;
	int x,j=0,u=0;
	for(int i;i<=n;i++){
		cin>>x;
		if(pd(x)){
			j++;
	    	a[j]=x;
		}
		else{
			u++;
		    b[u]=x;	
		}
		ma=max(ma,x);
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	sort(a+1,a+j+1);
	sort(b+1,b+u+1);
	mi=a[n];
	for(int i=0;i<m;i++){
		if(i>j){
			mi=hs(mi,b[i-j]);
		}
		else{
			mi=hs(mi,a[n-i]);
		}
	}
	cout<<mi;
	return 0;
}
