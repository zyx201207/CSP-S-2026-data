//GZ-S00364 遵义市第四中学 隆银艳
#include<bits/stdc++.h>
using namespace std;
long long m,a[500010];
int tong,n,pi[500010],shu;//pi[]用来存储下标
int check(int cha){
	long long sum=0;
	for(int i=1;i<cha;i++){
		sum+=a[cha]-a[i];
	}
	if(sum>m) return 1;
	else return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool deng=true;//用来判断是否是等差数列
	int maxx=1;
	for(int i=1;i<=n;i++) cin>>a[i];//常规输入 0
	sort(a+1,a+n+1);//排序
	long long chashu=a[2]-a[1];//储存差数
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			tong++;
			maxx=max(maxx,tong);
		}else tong=1;
		if(a[i]-a[i-1]!=chashu){//判断等差数列 循环不溢出
			deng=false;
		}
	}
	if(deng){
		for(int i=n;i>=1;i--){
			m-=a[n]-a[i];
			shu=i;
			if(m<0){
				cout<<n-shu;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)) r=mid-1;
		else l=mid;
	}
	if(l==1) cout<<maxx;
	else cout<<l;
	return 0;
//	fclose(stdin);
//	fclose(stdout);
}

