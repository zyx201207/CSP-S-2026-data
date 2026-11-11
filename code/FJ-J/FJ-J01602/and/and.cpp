#include<bits/stdc++.h>
using namespace std;
const int N=200005;
struct note{
	int ys;
	int f[35];
	int gs;
};
int a[N+1];
note s[N+1];
int g[35];
int n;
queue<note> q;
int ans,qs;
int solve(int m,int k){
	if(k<0||qs==m){
		note x1=q.front();
		q.pop();
		ans=x1.ys;
		while(!q.empty()){
			note x=q.front();
			q.pop();
			ans=ans&x.ys;
		}
		return 0;
	}
	else{
		int gs1=qs;
		int j1=qs;
		while(j1>0){
			note x=q.front();
			q.pop();
			q.push(x);
			if(x.f[k]==0){
				gs1--;
			}
			j1--;
		}
		if(gs1>=m){
			int j2=gs1;
			while(j2>0){
			    note x=q.front();
			    q.pop();
				if(x.f[k]==1){
					q.push(x);
				}
				j2--;		
			}
			qs=gs1;
			return solve(m,k-1);
		}
		else{
			return solve(m,k-1);
		}
	}
	return 0;
}
int fj(int i,int x){
	s[i].ys=x;	
	int j=0;
	while(x>0){
		s[i].f[j]=x%2;
		j++;
		x=x/2;
	}
	s[i].gs=j;
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		fj(i,a[i]);
	}
	int i1=s[n-1].gs;
	for(int i=0;i<n;i++){
		for(int j=i1-1;j>=0;j--){
			if(s[i].f[j]==1){
				g[j]++;
			}
		}
	}
	int i2=s[n-1].gs-1;
	while(i2>=0&&g[i2]<m){
		i2--;
	}
	for(int i=0;i<n;i++){
		if(s[i].f[i2]==1){
			q.push(s[i]);
			qs++;
		}
	}
	solve(m,i2);
	printf("%d",ans);
	return 0;
}
