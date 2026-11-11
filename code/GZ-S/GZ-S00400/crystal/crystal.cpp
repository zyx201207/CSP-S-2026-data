//GZ-00400 毕节梁才学校 张静峰 
#include<bits/stdc++.h>
using namespace std;


typedef long long LL;
const int N=5e5+10; 

LL n,m;
LL a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	} 
	sort(a+1,a+1+n);
	LL t=m;//当前剩余 
	int ans=0;
	for(int i=1,j=1;j<=n;j++){
		LL c=(j-i)*(a[j]-a[j-1]);
		if(t>=c) t-=c;
		else{
			while(i<j&&t<(j-i)*(a[j]-a[j-1])){
				t+=a[j-1]-a[i];
				i++;
			}
			if(j>i&&t>=(j-i)*(a[j]-a[j-1])) t-=(j-i)*(a[j]-a[j-1]);
		}
		ans=max(ans,j-i+1);
	}
	cout<<ans;
	return 0;
}
