#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],s,sl;
int main (){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)if(i>1)b[i-1]=a[i]-a[i-1];
	for(int i=n;i>1;i--){
		int t=m,yh=0;sl=1;
		while(i-sl>0){
			yh+=b[i-sl];
			t-=yh;
			if(t<0)break;
			sl++;
		}
		s=max(s,sl);
	}
	cout<<s<<yh;
	return 0;
}
