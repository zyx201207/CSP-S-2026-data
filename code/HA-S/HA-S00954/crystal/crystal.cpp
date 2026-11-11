#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long n,m,a[500010],b[500010],sum,ans=-1,tt=1,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n >>m;
	for(int i=1;i<=n;i++) cin >>a[i];
	sort(a+1,a+1+n);
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		int c1=cnt;
		cnt+=(i-tt)*(a[i]-a[i-1]);
		sum++;
		if(cnt<0){
			int t=tt;
			while(1){
				cnt=c1;
				cnt-=a[i]-a[tt];
				tt++;
				sum--;
				c1=cnt;
				cnt+=(i-t)*(a[i]-a[i-1]);
				if(cnt>=0) break;
			}
		}
		else if(cnt<=m){
			ans=max(sum,ans);
		}else{
			while(cnt>m){
				cnt-=a[i]-a[tt];
				tt++;
				sum--;
				//cout <<cnt <<" "<<tt  <<" "<<sum <<" "<<i <<endl;
			}
			ans=max(sum,ans);
		}
	//	cout <<sum<<" " <<cnt<<" " <<tt <<endl;
	}
	cout <<ans;
	return 0;
}
/*
CSP-S qi yu ji
dao kao chang le,rang wo yan yan ji zi
shen me jiao mei you jian pan?
shen me jiao shu biao mei lian?
(shu ju shan chu)ccf
zui hong ban xiao shi bu chong ti mian,ccf zhen shen le
*/
