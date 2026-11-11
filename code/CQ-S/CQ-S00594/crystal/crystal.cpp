#include<bits/stdc++.h>
#define int long long
//#define double long double
using namespace std;
const int M=5e5+5,INF=1e18;
int n,m,sum,ans,cnt,sum_cha,last/*最后满足条件的那个数*/,pingjun;
struct sr{
	int a;
}a[M];
bool cmp(const sr&x,const sr&y){
	return x.a<y.a;
}
int suan_pingjun(int pingjun){
	int as=pingjun;
	sum_cha=0; //清零！ 
	cnt=0;
	for(int i=1;i<=n;i++){
    	if(sum_cha>m){
    		as--;
    		return suan_pingjun(as);
		}
    	if(a[i].a<=pingjun){
    		cnt++;
    		sum_cha+=pingjun-a[i].a;
		}
    	else{
    		ans=cnt;
    		return as;
		}
	}
	return as;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    priority_queue<int,vector<int>,greater<int> > h;
    for(int i=1;i<=n;i++){
    	scanf("%lld",&a[i].a);
    	sum+=a[i].a;
	}
    sort(a+1,a+n+1,cmp);
    pingjun=ceil(sum*1.0/n); //算平均值 
    for(int i=1;i<=n;i++){
    	if(a[i].a>pingjun){
    		pingjun=a[i].a;
    		break;
		}
	}
	pingjun=suan_pingjun(pingjun);
	cout<<ans<<'\n';
	return 0;
}
/*
5 5
1 2 4 8 9
//3
*/
/*
5 8
-3 -1 2 2 7
//4
*/
