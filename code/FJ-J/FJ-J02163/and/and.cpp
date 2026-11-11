#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,l,r;
long long a[N],b[N],cnt,ans,v[31];
bool f[N];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int x=30;
	while(x>=0){
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++){
			if(f[i])continue;
			int o=0;
			for(int j=1;j<=a[i];j<<=1){
				if(a[i]&j)v[o]++;
				o++;
			}
		}
		while(v[x]<m && x>=0){
			x--;
		}
		for(int i=1;i<=n;i++){
			if(!(a[i]&(1<<x)))f[i]=1;
		}
		x--;
		
		if(x<-1)break;
		//if(x==-2)x++;
		//cout<<x<<" "<<ans<<endl;
		ans+=(1<<(x+1));
		//for(int i=1;i<=30;i++)cout<<v[i]<<" ";
		//cout<<endl;
		
	}
	cout<<ans<<endl;
	return 0;
} 
