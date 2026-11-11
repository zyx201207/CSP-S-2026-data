#include<bits/stdc++.h>
using namespace std;
long long n,m,a[501010],z,s=(1<<30)-1,k,f,zz=1,c,d,l,bb=(1<<30)-1;
void dfs(long long x,long long z){
	if(x==0) {
		l=max(z,l);
		return ;	
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=0){
			long long u=a[i];
			
			a[i]=0;
			dfs(x-1,u&z);
			a[i]=u;
		}                                           
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>z){
			z=a[i];
			zz=1;
		}else if(a[i]==z) zz++;
		s=s&a[i];
		if(c==0){
			int h=0;
			d=1;
			for(int i=0;i<=30;i++){
				if((d*=2)-1==a[i]){
					h=1;
					break;
				}
			}
				
			if(h==0) c=1;
		}
	}
	if(zz>=m){
		cout<<z;
		return 0;
	}if(m==n){
		cout<<s;
		return 0;
	}if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				k=a[i]&a[j];
				f=max(f,k);
			}
		}
		cout<<f;
		return 0;
	}
	if(z<4){
		for(int i=1;i<=n;i++){
			if(a[i]==3) k++;
			if(a[i]==2) f++;
		}
		if(k>=m){
			cout<<"3";
			return 0;
		}else if(k+f>=m){
			cout<<"2";
			return 0;
		} 
		cout<<"1";
		return 0;
	}	
	if(c==0){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	if(n<2000){
		l=0;
		dfs(m,(1<<30)-1);
		cout<<l;
		return 0;
	}
	for(int i=n;i>=n-m+1;i--) bb=bb&a[i];
	cout<<bb;
	return 0;
} 
