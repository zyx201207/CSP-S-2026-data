#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,m;
long long a[MAXN];
long long ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++){
		if(ans&a[i]==0){
			if(m==n);
			else {
				m++;
				continue;
			}
		}
		ans&=a[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
