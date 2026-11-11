#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
ll ans=1;//无论如何至少能有一个水晶 
ll a[500005];
ll sum[500005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//统计初始各能量值水晶个数 
		sum[a[i]]++;
	}
	
	//*特殊性质A*
	bool flagA = 1;
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			flagA = 0;
			break;
		}
	}
	if(flagA){
		double sd=m*2.00;
		//向下取整
		ll x=floor(sqrt(sd+0.250)-0.50);
		
		ans = min(n,x+1);//超过了也不行 
		
		cout<<ans;
		return 0; 
	}
	
	sort(a+1,a+n+1);//排序 
	
	/*	特殊性质B
	先判断是否等差数列	*/
	bool flagB = 1;
	ll e=a[2]-a[1];//差值 
	for(int i=3;i<=n;i++){
		if( a[i]-a[i-1] != e){
			flagB = 0;
			break;//不等差就退出 
		}
	}
	if(flagB){//如果是等差数列
		/*由于每相邻两个水晶差值相同
		所以可以快速计算所需操作次数 */
		ll s=m/e;	//计算 能加多少个单位
		//数学方程化简 
		double sd=s*2.00;
		//向下取整
		ll x=floor(sqrt(sd+0.250)-0.50);
		
		ans = min(n,x+1);//超过了也不行 
		
		cout<<ans;
		return 0; 
	}
	
	//枚举 
	//将第i个水晶的能量值 当做指标 
	for(int i=1;i<=n;i++){
		
		//如果能量跟上一个一样就跳过 
		if(a[i]==a[i-1]){
			continue;
		}else if(a[i]-a[i-1] > m){
			//如果一个都加不到就按原本个数 
			ans=max(sum[a[i]],ans);
			continue;
		}
		
		ll k=m;
		ll sumai=sum[a[i]];
		for(int j=i-1;j>0;j--){
			//计算第j个跟第i个水晶的差值
			ll e=a[i]-a[j];
//			cout<<"e = "<<e<<"\n";
			if(e<=k){  //如果能加到 
				k-=e; //消耗操作次数
//				cout<<"k = "<<k<<"\n";
				sumai++; //能量为a[i]的水晶增加 
			}else{
				break; //不够加 就停止 
			}
//			cout<<"sumai = "<<sumai<<"   ans = "<<ans<<"\n\n";
		}
		ans = max(ans,sumai);//更新答案 
	}
	
	cout<<ans;
	
	return 0;
}
