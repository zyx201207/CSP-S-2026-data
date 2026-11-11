#include <bits/stdc++.h> 
using namespace std;
int n,m,a[500005],s,tot,an[500005],ans,b[500005];
void solve(int n,int k){
	s=0;ans=0;
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++) s+=a[i];
	int mid=s/n;
	for(int i=1;i<=n;i++){
		b[i]=mid-a[i];
		if(b[i]-mid>=m) b[i]=0;
		if(b[i]>=0&&k>=b[i]){
			k-=b[i];
			ans++;
			a[i]=mid;
		}	
	}
	if(k>0) solve(n,k);
	else return;  
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	solve(n,m);
	printf("%d",ans); 
	return 0;
}

