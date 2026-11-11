#include<bits/stdc++.h>
using namespace std;

int n,ans,flag=1;
long long m,a[500010],s[500010];	
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+a[i];
		if(s[i]!=i*a[i]){
			flag=0;
		}
	}
	if(flag){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			int x=s[i]-s[j];//第j+1个到 第i个的和
			int k=a[i]*(i-j)-x;
			if(k>m) continue;
			else{
				ans=max(ans,i-j);
			}
		}
	}
	cout<<ans;
	return 0;
}
