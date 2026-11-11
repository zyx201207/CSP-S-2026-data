//刘子逍 北京师范大学贵阳附属中学 GZ-J00306
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
int n,m,ans;
int a[200010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	//freopen(".in","r",stdin);freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=2;i<=m;++i) ans&=a[i];
	cout<<ans<<'\n';
	//fclose(stdin);fclose(stdout);
	return 0;
}

