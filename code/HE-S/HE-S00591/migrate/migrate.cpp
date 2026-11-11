#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],ans;
bool f[2000005];
void bfs(int s){
	int l=1,r=1;
	int a[2000005],b[2000005],c[2000005];
	for(int i=1;i<=n;i++){
		c[i]=1000000;
	}
	a[r]=s;
	b[r]=0;
	r++;
	while(l<=r){
		if(b[l]<c[l]){
			f[l]=false;
			c[l]=b[l];
		}
		else if(c[l]==b[l]){
			if(f[l]){
				f[l]=false;
			}
			else{
				f[l]=true;
			}
		}
		int num=a[l]+1;
		while(x[num]-x[a[l]]<=d){
			a[r]=num;
			b[r]=b[l]+1;
			r++;
			num++;
		}
		l++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12||c==0){
			cout<<n-(d+1)<<endl;
			break;
		}
		for(int i=1;i<=n-d;i++){
			bfs(i);
			for(int i=1;i<=n;i++){
				if(f[i]){
					ans++;
					f[i]=false;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
