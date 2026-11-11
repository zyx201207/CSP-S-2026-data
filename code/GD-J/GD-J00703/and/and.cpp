#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+10;
int n,m;
long long a[N];
long long ma;
int flag[N];
bool cmp(long long x,long long y){
	return x>y;
}
void dfs(int x,long long num){
	if(x==m+1){
		ma=max(ma,num);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			if(num==0){
				flag[i]=1;
				dfs(x+1,a[i]);
				flag[i]=0;
			}else{
				flag[i]=1;
				dfs(x+1,num&a[i]);
				flag[i]=0;
			}
		}
	}
	return ; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n<=2000){
		if(m==2){
			for(int i=1;i<=n;i++) cin>>a[i];
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					ma=max(ma,(a[i]&a[j]));
				}
			}
			cout<<ma;
			return 0;
		}else if(m==n){
			for(int i=1;i<=n;i++){
				cin>>a[i];
				if(i==1) ma=a[i];
				else ma&=a[i];
			}
			cout<<ma;
			return 0;
		}else{
			for(int i=1;i<=n;i++) cin>>a[i];
			dfs(1,0);
			cout<<ma;
			return 0;
		}
	}
	if(m==1){
		ma=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ma=max(a[i],ma);
		}
		cout<<ma;
		return 0;
	}
	int num=n;
	bool s=0;
	while(1){
		if(num==1){
			s=1;
			break;
		}
		if(num%2==1) break;
		num/=2;
	}
	if(s){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]!=i-1){
				s=0;
				break;
			}
		}
		if(s){
			for(int i=1;i<=m;i++){
				if(i==1) ma=a[i];
				else ma&=a[i];
			}
			cout<<ma;
			return 0;
		}
	}
	s=1;
	bool ss=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(s){
			num=a[i];
			s=0;
			while(1){
				if(num==1){
					s=1;
					break;
				}
				if(num%2==1) break;
				num/=2;
			}
		}
		if(a[i]>=4) ss=0;
	}
	if(s||ss){
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=m;i++){
			if(i==1) ma=a[i];
			else ma&=a[i];
		}
		cout<<ma;
		return 0;
	}
	return 0;
} 
