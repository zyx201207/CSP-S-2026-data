#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[10005],ans=0;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		int cnt=0,M=m;
		for(int j=i;j>=1;j--) 
		if(m-(a[i]-a[j])>=0){
			M=M-(a[i]-a[j])>=0;
			cnt++;
		}
		if(ans>cnt)break;
		ans=cnt;
	}
	cout<<ans;
	return 0;
}



