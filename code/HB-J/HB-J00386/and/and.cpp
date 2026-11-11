#include <bits/stdc++.h>

using namespace std;

#define N 200010

int n,m,a[N];
int num[N];
int maxn=0;

void dfs(int step,int sum){
	if(step==m+1){
		maxn=max(maxn,sum);
		return ;
	}
	for(int i=num[step-1]+1;i<=n;i++){
		num[step]=i;
		dfs(step+1,sum&a[i]);
	}
	return ;
}

bool check(int x){
	for(int i=1;i<=20;i++){
		if(x==pow(2,i)-1) return true;
	}
	return false;
}

bool check2(int x){
	for(int i=1;i<=20;i++){
		if(x==pow(2,i)) return true;
	}
	return false;
}

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int ans1=-1,ans2=-1,ans3=2147483647;
	bool fl1=true,fl2=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans1=max(ans1,a[i]);
		ans3=ans3&a[i];
		if(!check(a[i])) fl1=false;
	}
	if(!check2(n)) fl2=false;
	if(m==1){cout<<ans1;return 0;}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ans2=max(ans2,(a[i]&a[j]));
			}
		}
		cout<<ans2;return 0;
	}
	if(m==n){cout<<ans3;return 0;}
	if(m==n-1){
		int ans4=2147483647,mm=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) ans4=ans4&a[j];
			}
			mm=max(mm,ans4);
			ans4=2147483647;
		}
		cout<<mm;return 0;
	}
	if(fl1){
		int b[N];
		for(int i=1;i<=n;i++) b[i]=a[i];
		sort(b+1,b+1+n,cmp);
		cout<<b[m];return 0;
	}
	if(fl2&&m==1){cout<<a[n];return 0;}
	dfs(1,2147483647);
	cout<<maxn;
	return 0;
}
