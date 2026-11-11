#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,a[1000024];
struct coco{
	int zhanting,zhantai;
}sum[524][100024];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		long long s;
		cin>>s;
		for(int j=1;j<=s;j++){
			cin>>sum[i][j].zhantai>>sum[i][j].zhanting;
		}long long x,y;
		cin>>x>>y;
		cout<<a[x]+a[y]<<endl;
	}
	return 0;
}

