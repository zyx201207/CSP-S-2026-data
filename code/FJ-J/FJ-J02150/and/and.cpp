#include<bits/stdc++.h>
using namespace std;
long long x[200005];
int a[200005][35];
int mj=-1; 
void f(int i,long long x){
	int j=1;
	while(x){
		if(x%2==1){
			a[i][j]=1;
		}else{
			a[i][j]=0;
		}
		x/=2;
		j++;
	}
	mj=max(mj,j); 
}
long long ff(int i){
	long long sz=1;
	for(int j=1;j<i;j++){
		sz*=2;
	}
	return sz;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	if(m==1){
		long long tmax=-1;
	    for(int i=1;i<=n;i++){
		    cin>>x[i];
		    tmax=max(tmax,x[i]);
		    f(i,x[i]);
	    }
		cout<<tmax<<"\n";
		return 0;
	}
	
	if(n==m){
	    for(int i=1;i<=n;i++){
		    cin>>x[i];
		    f(i,x[i]);
	    }
		long long ans=0;
		for(int j=1;j<=mj;j++){
			int sz=1;
			for(int i=1;i<=n;i++){
				sz&=a[i][j];
			}
			ans+=sz*ff(j);
		}
		cout<<ans<<"\n";
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	sort(x+1,x+1+n,greater<int>());
	for(int i=1;i<=m;i++){
		f(i,x[i]);
	}
	long long ans=0;
	for(int j=1;j<=mj;j++){
		int sz=1;
		for(int i=1;i<=m;i++){
			sz&=a[i][j];
		}
		ans+=sz*ff(j);
	}
	cout<<ans<<"\n";
	return 0;
}
