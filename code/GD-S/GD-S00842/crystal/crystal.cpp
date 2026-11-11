#include<bits/stdc++.h>
using namespace std;
using LL = long long;

LL n,m,ans=-1e18;
LL a[500010];
LL amax=-1e18,amin=1e18;

void solveA(){  //处理全部都==i的情况 
	ans=1;
	LL ti=0;
	for(LL i=n-1;i>=1;i--){
		ti+=a[n]-a[i];
		if(ti>m)break;
		else ans++;
	}
	cout << ans << '\n';
	return;
}

void solveB(int minn){  //todo
	ans=1;
	for(LL i=1;i<=m;i++){
		if(m-i*minn>=0){
			ans++;
			m-=i*minn;
		}
	}
	cout << ans << '\n';
}

vector<vector<LL>> initt(){   //获取变到第i项时要变多少次,[i][j]表示目标为i,当前第j个要变多少次 
	vector<vector<LL>> deal;
	deal.resize(n+1);
	for(LL i=1;i<=n;i++){
		deal[i].resize(i+1);
		for(LL j=1;j<i;j++){
			deal[i][j]=a[i]-a[j];
		}
	}
	return deal;
}

void solveN(){
	
	vector<vector<long long>>times=initt();
	for(LL i=1;i<=n;i++){
		LL tmpsum=0;
		LL tmpans=1;
		for(LL j=i-1;j>=1;j--){
			tmpsum+=times[i][j];
			if(tmpsum>m)break;
			tmpans++;
		}
		ans=max(tmpans,ans);
	}
	
	cout << ans << '\n';
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	bool isA=true;
	bool isB=true;
	int minn=0;
	cin >> n >> m;
	
	for(LL i=1;i<=n;i++){  //输入 
		cin >> a[i];
		amax=max(amax,a[i]);
		amin=min(amin,a[i]);
		if(a[i]!=i)isA=false;
		if(i==2)minn=a[2]-a[1];
		if(a[i]>2){
			if(a[i]-a[i-1]!=minn){
				isB=false;
			}
		}
	}
	
	sort(a+1,a+n+1);
	if(isA)solveA();
	else if(isB)solveB(minn);
	else solveN();

	return 0;
}

