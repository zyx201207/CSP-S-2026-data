#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010];
int sh(long long x){
	double t=(double)x;
	while(t>1){
		t/=2;
	}
	if(t==1.0){
		return 1;
	}
	else{
		return 0;
	}
}
int ys(int g){
	if(sh(g)){
		return 1;
	}
	else{
		long long y=g,ans=0;
		while(y>0){
			if(y%2==0){
				y/=2;
			}
			else{
				ans++;
				y/=2;
			}
		}
		return ans;
	}
}
struct node{
	long long a1,gs;
}b[200010];
bool cmp(node j,node k){
	return j.gs>k.gs;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i].a1=a[i];
		b[i].gs=ys(a[i]);
	}
	long long maxv=INT_MIN;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxv=max(maxv,a[i]&a[j]);
			}
		}
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			maxv=max(maxv,a[i]);
		}
	}
	else if(m==n){
		maxv=a[1];
		for(int i=2;i<=n;i++){
			maxv=maxv&a[i];
		}
	}
	else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int d=j+1;d<=n;d++){
					maxv=max(maxv,a[i]&a[j]&a[d]);
				}
			}
		}
	}
	else if(m==n-1){
		for(int i=1;i<=n;i++){
			long long yh,st=2;
			if(i==1){
				yh=a[2];
				st=3;
			}
			else{
				yh=a[1];
			}
			for(int j=st;j<=n;j++){
				if(j==i){
					continue;
				}
				else{
					yh=yh&a[j];
				}
			}
			maxv=max(maxv,yh);
		}
	}
	else{
		sort(b+1,b+n+1,cmp);
		maxv=b[1].a1;
		for(int i=2;i<=m;i++){
			maxv&=b[i].a1;
		}
	}
	cout<<maxv;
}
