#include<bits/stdc++.h>
#define int long long
using namespace std;

//TYX
/*
 * 
	09:42  100+100+?
	GouZAO de T3
	2026T3==2025T3+114514/10086 PRO MAX oppo
	11；03 100+100+？+76
	* T3 TMD 
	* 非人哉！与人出题……
	* 用LℹKaicheng + Chenyanzhe01 114514年阳寿 300++
	* Parhaps
	* Xebec
	* Run
	* S H I T
	* //11:16
	* 100+100+60+48=308
	 JOJO
	       |
	      / \
		  /\ /\
		  * 新算法：（平衡树线段树红黑树背包状压树上DP拌水泥混凝土拌chenyanzhe01拌意大利面）
		  * //freopen("travel.in","r",stdin);
		  * 上大赏QAQ
		  * 我不做人类了！
	CCF好阴！
	* MD 没有打表题
	* 签到+模拟+2025T3pro(DP)+?(模拟48）
	*/

int dp[2010][2010],a[2010];
int T[100];
int pow_(int n){
	if(n==1)return 2;
	int ans=pow_(n/2);
	if(n%2)return 2*ans*ans;
	return ans*ans;
}
signed main(){
	
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==n-1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int mx=0;
		for(int i=1;i<=n;i++){
			int ansss;
			if(i!=1)ansss=a[1];
			else ansss=a[2]
			for(int j=1;j<=n;j++){
				if(j!=i){	
					ansss&=a[j];
				}
			}
			mx=max(mx,ansss);
		}cout<<mx;
		return 0;
		
	}
	if(m==n){
		int ansss;
		cin>>ansss;
		for(int i=2;i<=n;i++){
			int fff;
			cin>>fff;
			ansss&=fff;
		}
		cout<<ansss;
		return 0;
	}
	if(m==1){
		int ansss;
		cin>>ansss;
		for(int i=2;i<=n;i++){
			int fff;
			cin>>fff;
			ansss=max(fff,ansss);
		}
		cout<<ansss;
		return 0;
	}if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int mx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,(a[i]&a[j]));
			}
		}
		cout<<mx;
		return 0;
	}
	int mmx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mmx=max(mmx,a[i]);
	}
	if(mmx<=4){
		for(int i=1;i<=n;i++)T[a[i]]++;
		if(m<=T[4]){
			cout<<4;
		}
		else{
			if(m<=T[3])cout<<3;
			else{
				if(m<=(T[3]+T[2])){
					cout<<2;
				}
				else if(m<=(T[3]+T[1])){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}
		return 0;
	}
	dp[0][0]=pow_(32);
	dp[0][0]--;
	

	for(int i=1;i<=n;i++){
		for(int j=1;j<=i&&j<=m;j++){
			for(int k=0;k<i;k++){
				dp[i][j]=max(dp[k][j-1]&a[i],dp[i][j]);
			}
		}
	}
	cout<<dp[n][m];
    return 0;
}
