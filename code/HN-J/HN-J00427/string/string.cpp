#include<bits/stdc++.h>
#define pii pair<int,int>
#define yi first
#define er second
const int MAX_N=2E5+78;
using namespace std;
long long n,cnt=0,now=-10,sum[MAX_N],ld=1,SUM,ans;
vector <pii> a;
long long get(int id){
	return upper_bound(sum+1,sum+ld+1,id)-sum-1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a.resize(n+1);
	for(int i=1;i<=n;i++){
		char ch;
		int q;
		cin>>q>>ch;
		SUM+=q;
//		cout<<ch<<' ';
		if(ch-'a'==now){
			cnt+=q;
		}else{
			if(now!=-10){
				a[ld]={now,cnt};
				sum[ld]=sum[ld-1]+cnt;
//				cout<<cnt<<'\n';
				ld++;
				cnt=q;
			}else{
				cnt=q;
			}
			now=ch-'a';
		}
//		cout<<ld<<'\n';
	}
	a[ld]={now,cnt};
	sum[ld]=sum[ld-1]+cnt;
//	for(int i=0;i<=n;i++){
//		cout<<sum[i]<<' '<<a[i].yi<<' '<<a[i].er<<'\n';
//	}
	int Sum=0;
	for(int i=1;i<=ld;i++){
		int G=get(Sum);
		if(G>=ld/2){
			//超越一半 
			break;
		}
		int zL=Sum+1;
		Sum+=a[i].er;
		int zR=Sum;
		int yL_id=get(SUM-zR);
		int yR_id=get(SUM-zL);
		
		if(yL_id==yR_id){
			//1.右LR对应同一段区间
			if(a[i].yi!=a[yL_id].yi){
				ans+=a[i].er;
				//全部更改 
			}
		}else{
			//对应不相同，看看哪些要改，之前维护过
			//前缀和了，所以可以快速获取
//			int mid=get(sum[yl]);
			int yL=sum[yL_id],yR=sum[yR_id];
			if(a[yL_id].yi!=a[i].yi){
				ans+=yR-SUM+zR;
			}
			if(a[yR_id].yi!=a[i].yi){
				ans+=sum[yR_id]-zL;
			}
		}
	}
	cout<<ans;
}
/*
统计L
 
*/
