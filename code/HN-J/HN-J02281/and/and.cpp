#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005],f[200005];
string c;
int vt(int b){
	while(b>0){
		c+=(b%2+'0');
		b/=2;
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	cout << vt(a[1])
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)
		{
			ans+=(vt(a[i])-'0' & vt(a[j])-'0');
		}
		f[i]=ans;
		break;
	}
	int maxn=-1;
	for (int i=1;i<=n;i++){
		maxn=max(maxn,f[i]);
	}
	cout << maxn; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
