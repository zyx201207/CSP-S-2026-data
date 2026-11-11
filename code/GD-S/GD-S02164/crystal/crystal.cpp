#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10;
int n,m;
int a[N];
int c[N];
int ans=0;
bool oka=true;
bool okb=true;
bool cmp(int a,int b){
	return a<b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=i) oka=false;
	}
	int ww=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=ww) okb=false;
	}
	sort(a+1,a+1+n,cmp);
	if(!oka && !okb){
		for(int i=1;i<=n;i++){
		int sum=0,cnt=0;
			for(int j=1;j<=i;j++){
				c[j]=a[i]-a[j];
			}
			sort(c+1,c+i+1,cmp);
			for(int j=1;j<=i;j++){
				if(sum+c[j]<=m){
					sum+=c[j];
					cnt++;
				}
				else break;
			}
			ans=max(ans,cnt);
		}
		cout << ans;
		return 0;
	}
	if(oka){
		int cnt=0,cnt_=0;
		for(int i=1;i<=n;i++){
			c[i]=1;
		}
		int ans_;
		for(int i=1;i<=n;i++){
			ans_=i*(i-1)/2;
			if(ans_<=m){
				cnt_=i;
				cnt=max(cnt_,cnt);
			}
			else break;
		}
		cout << cnt;
		return 0;
	}
	if(okb){
		//cout << ww << endl;
		int cnt=0,cnt_=0;
		for(int i=1;i<=n;i++){
			c[i]=ww;
		}
		int ans_=0;
		for(int i=1;i<=n;i++){
			ans_+=ww*(i-1);
			if(ans_<=m){
				cnt_=i;
				cnt=max(cnt_,cnt);
				//cout << ans_ << "^";
			}
			else break;
		}
		cout << cnt;
		return 0;
	}
}
