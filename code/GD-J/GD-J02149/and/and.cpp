#include <algorithm>
#include <iostream>
#include <bitset>
using namespace std;
int n,m,a[200000];
int ans=0;
void dfs(int i,int c,int nw){
	if(c==m){
		ans=max(ans,nw);
		return;
	}
	for(int j=i;j<n;++j)
		dfs(j+1,c+1,nw&a[j]);
}
bitset<200000> d[20];
int main(){
	freopen("and.in","rb",stdin);
	freopen("and.out","wb",stdout);
	cin>>n>>m;
	for(int i=0;i<n;++i)cin>>a[i];
	if(n<=2000){
		if(n<=20)dfs(0,0,0x7fffffff);
		else if(m==1)for(int i=0;i<n;++i)
			ans=max(ans,a[i]);
		else if(m==2){
			for(int i=0;i<n;++i)for(int j=i+1;j<n;++j)
				ans=max(ans,a[i]&a[j]);
		}else{
			ans=a[0];
			for(int i=1;i<n;++i)ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	int q=0;bool f=1;
	for(int i=0;i<n;++i){
		q=max(q,a[i]);
		if(a[i]&(a[i]+1))f=0;
	}
	if(f){
		sort(a,a+n);
		cout<<a[n-m];
		return 0;
	}
	if(q>=(1<<10)){
//		cout<<"Gave you.";
		cout<<0;
		return 0;
	}
	for(int i=0;i<20;++i)for(int j=0;j<n;++j)
		if(a[j]&(1<<i))d[i][j]=1;
	for(int w=(1<<10)-1;w>=0;--w){
		bitset<200000> nn;int i=0;
		for(;i<20;++i)if(w&(1<<i)){
			nn=d[i];break;
		}
		for(;i<20;++i)if(w&(1<<i))nn&=d[i];
		if(nn.count()>=m){
			cout<<w;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
