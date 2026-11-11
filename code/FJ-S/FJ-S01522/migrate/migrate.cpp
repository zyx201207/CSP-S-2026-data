#include<bits/stdc++.h>
using namespace std;
long long a[5005],b[5005];
int dfs2(int l,int r,long long d,int ans,int c){
	b[l]=c;
	if(l==r){
		if(c==ans){
			return 1;
		}
		else{
			return 0;
		}
	}
	int i=l+1;
	int answ=0;
	while(a[i]-a[l]<=d&&i<=r){
		if(b[i]>=c+1){
			answ+=dfs2(i,r,d,ans,c+1);
		}
		
		i++;
	}
	return answ;
}
bool dfs(int l,int r,long long d){
	long long cnt=0;int ans=0;
	for(int i=l+1;i<=r;i++){
		cnt+=a[i]-a[i-1];
		if(cnt>d)return false;
		if(i==r){
			ans++;
			break;
		}
		else if(cnt+a[i+1]-a[i]>d){
			cnt=0;ans++;
		}
	}
//	if(l==1&&r==4){
//		cout<<ans;
//	}
	memset(b,0x3f,sizeof b);
	if(dfs2(l,r,d,ans,0)==2)return true;
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long n,ans=0,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(dfs(j,k,d))ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
