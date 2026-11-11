#include<bits/stdc++.h>
using namespace std;
int s=INT_MIN,x,ans,n,m;
bool f[200005][35],f1,p[40],f2[200005];
int a[40],b[200005],c[200005];
void js(int t,int h,int j){
	if(t>m){
		memset(p,1,sizeof(p));
		for(int i=1;i<t;i++){
			for(int z=1;z<=h;z++){
				if(!f[c[i]][z]||!p[z]){
					p[z]=false;
				}
			}
		}
		int o=1,q=0;
		for(int i=1;i<=h;i++){
			if(p[i]){
				q+=o;
			}
			o*=2;
		}
		ans=max(ans,q);
		return;
	}
	for(int i=t;i<=j;i++){
		if(!f2[i]){
			f2[i]=true;
			c[t]=b[i];
			js(t+1,h,j);
			c[t]=0;
			f2[i]=false;
		}
	}
}
void zx(int k){
	int j=1;
	for(int i=1;i<=n;i++){
		if(f[i][k]){
			b[j]=i;
			j++;
		}
	}
	j--;
	js(1,k,j);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		int j=1;
		while(x!=0){
			if(x%2==0){
				f[i][j]=false;
			}else{
				f[i][j]=true;
				a[j]++;
			}
			x/=2;
			j++;
		}
		s=max(s,j-1);
	}
	for(int i=s;i>=1;i--){
		if(a[i]>=m){
			f1=true;
			zx(i);
			cout<<ans;
			exit(0);
		}
	}
	if(!f1){
		cout<<0;
	}
	return 0;
}
