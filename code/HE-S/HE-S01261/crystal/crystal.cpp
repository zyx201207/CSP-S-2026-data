#include<bits/stdc++.h>
using namespace std; 
const int maxn=1e6+9;
long long m,a[maxn],d[maxn],n,ans;
bool cmp(int x,int y){
	return x<y;
}
bool check(int a,int b){
	long long ss=0;int t=1;
	for(int i=a;i<=b;i++){
		ss+=t*d[i];t++;
		if(ss>m) return false;
	}
	if(ss>m) return false;
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a[0]=0;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		a[i]=x;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<n;i++){
		d[i]=a[i+1]-a[i];
	}
	int flag=0;	
	for(int i=1;i<=n;i++) if(a[i]!=i) flag=1;
	if(flag==0){
		int t=1;long long ss=0;
		for(;;t++){
			ss+=t;
			if(ss>m){
				cout<<t-1;
				return 0;
			}
		}
	}
	flag=0;
	for(int i=2;i<=n-1;i++) if(d[i]!=d[i-1]) flag=1;
	if(flag==0){
		int t=1;long long ss=0;
		for(;;t++){
			ss+=t*d[1];
			if(ss>m){
				cout<<t-1;
				return 0;
			}
		}
	}
	for(long long i=n;i>=ans-5;i--){
		long long l=1,r=i;
		while(l<=r){
			long long mid=(l+r)/2;
			if(check(mid,i)){
				r=mid-1;
			}else l=mid+1;
		}
		ans=max(ans,i-l+2);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
