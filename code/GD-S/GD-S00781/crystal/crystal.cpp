#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=5e5+10;
LL a[maxn];
LL b[maxn];//前缀和 
LL n,m,ans=1;
int main(){ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	bool Pa=true;//特殊性质A
	bool Pb=true;//特B 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)Pa=false;
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])Pb=false;
	}
	//特殊性质A 
	if(Pa){
		LL tmp=0;
		for(int i=1;i<=n;i++){
			tmp=(i-1)*i/2;
			if(tmp>m){
				cout<<i-1<<"\n";
				return 0;
			}
		}
	}
	if(Pb){
		LL c=a[2]-a[1];//差值
		LL tmp=0;
		for(int i=1;i<=n;i++){
			tmp=c*(i-1)*i/2;
			if(tmp>m){
				cout<<i-1<<"\n";
				return 0;
			}
		} 
	}
	sort(a+1,a+1+n);
	b[0]=0;
	for(int i=1;i<=n;i++){//构造前缀和 
		b[i]=b[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		//要合成第i个大水晶
		LL x=0;//消耗
		for(int j=i-1;j>=1;j--){
			LL len=i-j;
			x+=a[i]*len-(b[i-1]-b[j-1]);
			if(x>m){
				ans=max(ans,(long long)i-j+1);//更新答案
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
