#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],s[N],d[N];
bool task1(){//1~5
	for(int i=1;i<=n;i++)if(a[i]>100)return false;
	int k,b[N],ans=0,answer,top;
	for(int mid=a[1];mid<=a[n];mid++){
		answer=0;
		k=m;
		top=0;
		for(int i=1;i<=n;i++){
		if(mid>=a[i])b[++top]=mid-a[i];
			else break;
		}
		sort(b+1,b+top+1);
		for(int i=1;i<=top;i++){
			k-=b[i];
			if(k<0)break;
			else answer++;
		}
		ans=max(ans,answer);
	}
	cout<<ans;
	return true;
}
bool task2(){//13~18
	int cha=a[2]-a[1];
	for(int i=3;i<=n;i++)if(cha!=a[i]-a[i-1])return false;
	int ans=0;
	for(int i=n;i>=1;i--){
		m=m-cha*(n-i);
		if(m<0)break;
		else ans++;
	}
	cout<<ans;
	return true;
}
bool task3(){//6~9
	int answer=0,ans=0,k;
	for(int i=n;i>=1;i--){
		k=m;
		answer=0;
		for(int j=i;j>=1;j--){
			k=k-(a[i]-a[j]);
			if(k>=0)answer++;
			else break;
		}
		ans=max(ans,answer);
	}
	cout<<ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(task1())return 0;
	if(task2())return 0;
	if(task3())return 0;
}
/*
4
*/
