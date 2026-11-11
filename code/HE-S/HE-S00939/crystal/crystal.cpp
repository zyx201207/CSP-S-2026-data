//贪心策略：越小的越优先安排增加能量 
#include<bits/stdc++.h>
using namespace  std;
long long a[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=1;
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);//按照贪心策略升序排序 
	if(m!=0||m<a[2]-a[1]){//排除m=0和最小的两个都无法合成的情况 
		m-=a[2]-a[1];//保证至少有2个可以合成 
		a[1]+=a[2]-a[1];
		for(long long i=2;i<=n;i++){//循环判定m次操作后的值
			if(m>=(a[i+1]-a[i])*i){
				m-=(a[i+1]-a[i])*i;
				for(int j=1;j<=i;j++) a[j]=a[i+1];
			}else break;
		}
	}
	for(int j=1;j<n;j++){//判断可合成的数量
		if(a[j]==a[j+1]) ans++;
		else break;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
