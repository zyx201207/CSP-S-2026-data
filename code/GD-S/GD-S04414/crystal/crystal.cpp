#include <bits/stdc++.h>
using namespace std;
using ll=long long;


const int N=5*1000*100+10;
long long a[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n;
	ll m;
	
	cin >>n>>m;
	
	for (int i=1;i<=n;i++){
		cin >>a[i];
	}
	
	sort(a+1,a+1+n);
	
	int j=0;
	ll tnt=a[1];//标准能量值 
	int len=0;//区间长度 
	int ans=1;
	ll cnt=0;//所用量 
	for (int i=1;i<=n;i++){
		while (j+1<=n&&cnt+(a[j+1]-tnt)*len<=m){
			cnt+=(a[j+1]-tnt)*len;
			
			j++;
			len++;
			tnt=a[j];
			
		}
		ans=max(ans,len);
//		cout <<len<<endl;
		
		cnt-=tnt-a[i];
		len--;
	}
	
	cout <<ans;

	return 0;
}
