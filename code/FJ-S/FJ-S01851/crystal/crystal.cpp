#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500005;
ll n,m,a[N],cha[N],qzh[N],ans=1,dis=0,op=1;//正常
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	qzh[1]=0;
	for(int i=2;i<=n;i++){
		qzh[i]=qzh[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	if(m>5000 && (a[3]-a[2]==a[2]-a[1]) )op=2;//找特殊性质 
	if(op==1){
		for(int i=1;i<=n;i++){//暴搜每个区间,测试点1~9 
			for(int j=i;j<=n;j++){
				dis=qzh[j]-qzh[i]-(i-1)*(a[j]-a[i]);//dis=区间差值总和 
				if(dis<=m){//够填满 
					if(ans<(ll)j-i+1)
						ans=(ll)j-i+1; //取最长区间
				}//我是一个二分查找 
				else break;//已排序，若m不够dis，后续必定没有更优解 
			}
		}
	}else if(op==2){
		qzh[n+1]=1000000000005; 
		for(int i=1;i<=n;i++){
			if(qzh[i]<=m && m<=qzh[i+1]){
				ans=i;
				break;
			}
		}
		if(ans==0)ans=1;
	}
	cout<<ans<<endl;
	return 0;
}
