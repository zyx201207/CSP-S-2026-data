#include<bits/stdc++.h>
using namespace std;
int a[200010],s[200010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)a[i]=i-1;
	if(n>2000){
		int kkkk=a[n];
		for(int i=n-1;i>=n-m+1;i--)kkkk&=a[i];
		cout<<kkkk;
		return 0;
	}
	
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++){
		int dq=i,cnt=a[i];
		for(int k=2;k<=m;k++){
			if(s[dq]){
				cnt&=a[s[dq]],dq=s[dq];
				continue;
			}
			int sum=0,x=0;
			for(int j=dq+1;j<=n;j++)
				if((a[dq]&a[j])>sum){
					x=j;
					sum=a[dq]&a[j];
				}
			s[dq]=x;
			dq=s[dq];
			cnt&=a[x];
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
