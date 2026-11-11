//GZ-J00499 贵阳市南明区华麟学校 陈锦江
#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
long long a[int(2e5+10086)],vis[int(2e5+10086)];
long long now,cnt;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,flag=1;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=i-1){
			flag=0;
		}
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==n){
		now=a[1];
		for(int i=2;i<=n;i++){
			now=now&a[i];
		}
		cout<<now;
		return 0;
	}
	now=a[1];
	for(int i=2;i<=m;i++){
		long long mx=-1,c;
		for(int j=2;j<=n;j++){
			if((now&a[j])>mx&&!vis[j]){
				mx=(now&a[j]);
				c=j;
			}
		}
		now=now&a[c];
		vis[c]=1;
	} 
	cout<<now;
	return 0;
}

