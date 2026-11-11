#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],m,maxx=-1,op[5];
set<long long> st;
void dfs(long long id,long long sum,long long k){
	if(k==m||id==n+1){
		if(k==m)maxx=max(maxx,sum);
		return;
	}
	dfs(id+1,sum,k);
	dfs(id+1,sum&a[id],k+1);
	return;
}
void init(){
	for(int i=1;i<=22;i++)st.insert(pow(2,i)-1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	cin>>n>>m;
	long long ma=-1,pd=0,pd1=0,pd2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i],ma=max(ma,a[i]);
		if(a[i]>=4)pd=1;
		if(a[i]<4)op[a[i]]++;
		if(!st.count(a[i]))pd1=1;
		if(a[i]!=i-1)pd2=1;
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	else if(m==n){
		long long aa=a[1];
		for(int i=2;i<=n;i++)aa&=a[i];
		cout<<aa;
		return 0;
	}
	else if(n<=20||m==2){
		long long at=pow(2,22)-1;
		dfs(1,at,0);
		cout<<maxx;
		return 0;
	}
	else if(!pd){
		long long ans=0;
		if(op[3])op[3]--,ans=3;
		else if(op[2])op[2]--,ans=2;
		else if(op[1])op[1]--,ans=1;
		else{
			cout<<0;
			return 0;
		}
		for(int i=3;i>=1;i--){
			while(m!=0&&op[i]){
				op[i]--;
				m--;
				ans&=i;
			}
		}
		cout<<ans;
		return 0;
	}
	else if(!pd1){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	else if(!pd2&&st.count(n-1)){
		long long hj=a[n];
		for(int i=n;i>=n-m+1;i--)hj&=a[i];
		cout<<hj;
		return 0;
	}
	else if(m==n-1){
		long long zm=-1;
		for(int i=1;i<=n;i++){
			long long jj=a[(i+1)%n];
			for(int j=1;j<=n;j++)if(j!=(i+1)%n&&j!=i)jj&=a[j];
			zm=max(zm,jj);
		}
		cout<<zm;
		return 0;
	}
	else cout<<1;
	return 0;
}
