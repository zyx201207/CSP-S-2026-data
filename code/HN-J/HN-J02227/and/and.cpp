#include<bits/stdc++.h>
using namespace std;

#define int long long


bool cmp1(int a,int b){
	return a>b;
}
vector<int>a;

void solve(int n,int m){
	int ans=0;
	for(int i=0;i<(1<<(n+1));i++){
		bitset<21>x(i);
		int cnt=0;
		for(int j=0;j<11;j++){
//			cout<<x[j]<<" ";
			if(x[j]==1){
				cnt++;
			}
		}
//		cout<<endl;
		if(cnt!=m){
			continue;
		}
		int tmp=0;
		for(int j=0;j<21;j++){
			if(x[j]==1){
				tmp=a[j];
				break;
			}
		}
		
		for(int j=0;j<21;j++){
			if(x[j]==1){
				tmp&=a[j];
			}
		}
		ans=max(tmp,ans);
	}
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	int n,m;
	
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	if(n<=20){
		solve(n,m);
		return 0;
	}
	sort(a.begin(),a.end(),cmp1);
	int ans=0;
	bool flg=1;	
	for(int j=0;j<10000;j++){
		int tmp=a[j];
		for(int i=j;i<j+m;i++){
			if(i>=n){
				flg=0;
				break;
			}
			tmp&=a[i];
		}
		if(!flg){
			break;
		}
		ans=max(tmp,ans);
	}

	flg=1;	
	mt19937 ra(114514);
	for(int i=0;i<10000;i++){
		
		for(int j=0;j<1000;j++){
			swap(a[ra()%n],a[ra()%n]);
		}
		int tmp=a[i];
		for(int j=i;j<i+m;j++){
			if(j>=n){
				flg=0;
				break;
			}
			tmp&=a[j];
		}
		if(!flg){
			break;
		}
		
		
		ans=max(tmp,ans);
	}
	cout<<ans<<endl;
	return 0;
}

//既然我生来难登楼台作为珠玉，就让我走出属于我的阶绿。 
