//GZ-J00316 遵义第十二中学 宋云帆 
#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}
long long a[200005],maxn[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans;
	cin >>n>>m;
	for(long long i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		maxn[i]=a[i];
	}
	ans=maxn[1];
	for(int i=1;i<=m;i++){
		ans=ans&maxn[i];
	}
	cout <<ans;
	fclose(stdin);
	fclose(stdout);
}

