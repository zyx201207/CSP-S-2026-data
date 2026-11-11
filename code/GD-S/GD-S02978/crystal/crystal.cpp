#include<bits/stdc++.h>
using namespace std;
const int NM=5e5+78;
long long a[NM],m,ans=1;
int n;
void dfs(int p){
	long long z=m,sum=1;
	int i=p-1;
	while(z>0&&i>=1){
		z-=(a[p]-a[i]);
		if(z<0) break;
		sum++;
		i--;
	}
	ans=max(ans,sum);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool flag=true;
	long long cha=0;
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(i==2) cha=a[2]-a[1];
		else if(cha!=a[i]-a[i-1]) flag=false;
	}
	if(flag){
		long long i=1;
		while(m>0){
			m-=i*cha;
			if(m<0) break;
			ans++;
			i++;
		}
		cout<<ans;
		return 0;	
	}
	else{
		sort(a+1,a+1+n);
		for(int i=2;i<=n;i++){
			dfs(i);
		} 
		cout<<ans;
	}
	return 0;
}
