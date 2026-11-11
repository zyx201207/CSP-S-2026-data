#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,f[N],a[N],b[N],ans[55],sum;
long long q[N],p[N];
long long  k,r;
bool cmp(int i,int j)
{
	return i>j;
}
void dfs(long long z){
	if(z<0)return;
	long long sz=0;
	for(int i=1;i<=r;i++){
		p[i]=q[i];
	}
	for(int i=1;i<=r;i++){
		if(q[i]==1&&(a[i]&(1<<z)))sz++;
		else q[i]=0;
	}
//	cout<<z<<' '<<sz<<endl;
	if(sz>=m){
		ans[z]=1;
	//	cout<<z<<endl;
		dfs(z-1);
		
	}
	else{
		for(int i=1;i<=r;i++){
			q[i]=p[i];
		}
		dfs(z-1);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=31;i++){
		b[i]=1<<i;
		if(a[m]<=b[i]){
			k=i-1;
			break;
		}
	}
		
		
	for(int i=1;i<=n;i++){
		if(a[i]<b[k]){
			r=i-1;
			break;
		}
		else{
			q[i]=1;
		}
	}
	ans[k]=1;
	dfs(k-1);
		
	for(int i=0;i<=40;i++){
		sum+=ans[i]*(1<<i);
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}









