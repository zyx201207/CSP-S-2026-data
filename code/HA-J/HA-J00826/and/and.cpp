#include<bits/stdc++.h>
using namespace std;
struct YHY{
	long long shu;
	long long er;
};
YHY a[1000000];
int xiwang[100000];
int n,m;
long long fx(long long shu){
	long long dishu = 1,weishu = 0,shu1 = shu,sum = 0;
	while(shu){
	    shu/=2;
	    weishu++;
	    dishu*=2;
	}
	dishu/=2;
	for(int i = weishu;i>=1;i--){
		if(shu1>=dishu){
			xiwang[i]++;
			if(xiwang[i]>=m){
				sum+=dishu;
			}
			shu1-=dishu;
		}
		dishu/=2;
	}
	return sum;
}
bool cmp(YHY a,YHY b){
	return a.er>b.er;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int i = 1;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
    	cin>>a[i].shu;
    	a[i].er = fx(a[i].shu);
    }
    if(m==1){
    	cout<<a[1].shu;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
   cout<<a[1].er;
	return 0;
}
