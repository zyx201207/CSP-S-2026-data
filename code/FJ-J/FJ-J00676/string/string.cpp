#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n;
struct node{
	int l,r;
	int lo;
	char ca;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int x=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].lo>>a[i].ca;
		a[i].l=x+1;
		x+=a[i].lo;
		a[i].r=x;
	}
	int mid=x/2;
	int mi;//标记中间位置 
	bool f=((x%2)&1);//是否为奇数 
	for(int i=1;i<=n;i++){
		if(a[i].l<=mid&&mid<=a[i].r){
			mi=i;
			break;
		}
	}
	//测试 
//	for(int i=1;i<=n;i++){
//		cout<<a[i].ca<<":"<<a[i].l<<"-"<<a[i].r<<"\n";
//	}
//	cout<<mi<<" "<<mid<<" "<<f<<"\n";
	//
	int ll=1,rr=n;
	int mil=1,mir=1,ans=0;
	while(ll<rr){
		//把mil+a[ll].lo-1(当前左侧所能到达的区间位置)
		//和mir+a[rr].lo-1(当前右侧所能到达的区间位置)
		if(mil+a[ll].lo-1>mir+a[rr].lo-1){
			//左边多,右边少
			mil=mir+a[rr].lo;
			mir+=a[rr].lo;
			if(a[ll].ca!=a[rr].ca){
				ans+=a[rr].lo;
			}
//			cout<<mil<<"--"<<mir<<"\n";
//			cout<<mil+a[ll].lo-1<<"-"<<mir+a[rr].lo-1<<"\n";
//			cout<<a[ll].lo<<"-?-"<<a[rr].lo<<"\n";
//			cout<<a[ll].ca<<"---"<<a[rr].ca<<"\n";
//			cout<<ll<<":"<<rr<<"\n";
			a[ll].lo-=a[rr].lo;
			a[rr].lo=0;
//			cout<<a[ll].lo<<"-?-"<<a[rr].lo<<"\n";
			rr--;
			continue;
		}
		if(mil+a[ll].lo-1<mir+a[rr].lo-1){	
			//左边少,右边多 
			mir=mil+a[ll].lo;
			mil=mir;
			if(a[ll].ca!=a[rr].ca){
				ans+=a[ll].lo;
			}
//			cout<<mil<<"--"<<mir<<"\n";
//			cout<<mil+a[ll].lo-1<<"-"<<mir+a[rr].lo-1<<"\n";
//			cout<<a[ll].lo<<"-?-"<<a[rr].lo<<"\n";
//			cout<<a[ll].ca<<"---"<<a[rr].ca<<"\n";
//			cout<<ll<<":"<<rr<<"\n";
			a[rr].lo-=a[ll].lo;
			a[ll].lo=0;
//			cout<<a[ll].lo<<"-?-"<<a[rr].lo<<"\n";
			ll++;
			continue;
		}
		//左右区间相等 共同推进
		mir=mil+a[ll].lo;
		mil=mir;
		if(a[ll].ca!=a[rr].ca){
			ans+=a[ll].lo;
		}
//		cout<<mil<<"--"<<mir<<"\n";
//		cout<<a[ll].ca<<"---"<<a[rr].ca<<"\n";
//		cout<<mil+a[ll].lo-1<<"-"<<mir+a[rr].lo-1<<"\n";
//		cout<<a[ll].lo<<"-?-"<<a[rr].lo<<"\n";
//		cout<<ll<<":"<<rr<<"\n";
		a[ll].lo=0;
		a[rr].lo=0;
//		cout<<a[ll].lo<<"-?-"<<a[rr].lo<<"\n";
		ll++;
		rr--;
	//	cout<<a[ll].lo<<"-"<<a[rr].lo<<"\n";
	}
//	cout<<a[ll].lo<<"-?-"<<a[rr].lo<<"\n";
	//测试 
//	for(int i=1;i<=n;i++){
//		cout<<a[i].ca<<":"<<a[i].lo<<"\n";
//	}
//	cout<<mi<<" "<<mid<<" "<<f<<"\n";
	//
	cout<<ans;
	return 0;
} 
