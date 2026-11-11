#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int a[200005],x=-1e9,n,m;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int l,int h,int sum){
	if(h==m){
		x=max(x,sum);
		return;
	}
	else if(l==n+1){
		return;
	}
	if(h==0){
		dfs(l+1,h+1,a[l]);
		dfs(l+1,h,sum);
	}
	else{
		dfs(l+1,h+1,sum&a[l]);
		dfs(l+1,h,sum);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int Max;
	bool fl=1,fla=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1){
			fl=0;
		}
		if(a[i]%2==0){
			fla=0;
		}
		Max=max(Max,a[i]);
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum=(sum&a[i]);
			return 0;
		}
		cout<<sum;
		return 0;
	}
	if(n<=10000&&m==2){
		int Max1=-1e9;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				Max1=max(Max1,(a[i]&a[j]));
			} 
		}
		cout<<Max1;
		return 0;
	}
	if(m==n-1){
		bool f=0;
		for(int i=1;i<=n-1;i++){
			if(a[i]==a[i+1]){
				f=1;
				break;
			}
		}
		int sum=a[1];
		for(int i=2;i<=n-1;i++){
			sum=sum&a[i];
		}
		if(f){
			sum=sum&a[n];
		}
		cout<<sum;
		return 0;
	}
	if(n<=20){
		dfs(1,0,0);
		cout<<x;
		return 0;
	}
	if(Max<4){
		int cnt=0,cnt1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==3){
				cnt++;
			}
			if(a[i]==2){
				cnt1++;
			}
		}
		if(cnt>=m){
			cout<<3;
			return 0;
		}
		if(cnt+cnt1>=m){
			cout<<2;
			return 0;
		}
		cout<<0;
		return 0;
	}
	if(fl){
		if(m>n/2){
			cout<<0;
			return 0;
		}
		if(m==n/2){
			cout<<n/2;
			return 0;
		}
		cout<<n-m;
		return 0;
	}
	if(fla){
		cout<<a[m];
		return 0;
	}
	if(n>10000&&Max*m<n&&m==2){
		for(int i=1;i<=n-1;i++){
			if(a[i]==a[i+1]){
				cout<<a[i];
				return 0;
			}
		}
		cout<<(a[1]&a[2]);
		return 0;
	}
	return 0;
}
