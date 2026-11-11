#include<bits/stdc++.h>
using namespace std;
int a[200100],used[35],tong[9],s1[200100],s2[200100];
int n,m,answer;
void dfs(int step,int ans){
	if(step==m){
		answer=max(ans,answer);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			used[i]=1;
			if(step==0){
				dfs(step+1,a[i]);
			}else{
				dfs(step+1,ans&a[i]);
			}
			used[i]=0;
		}
	}
	return;
}
bool check(){
	for(int i=1;i<=n;i++){
		if(a[i]>4)return false;
	}
	return true;
}
int power(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
bool check2(){
	for(int i=1;i<=n;i++){
		for(int k=0;k<=20;k++){
			int res=power(2,k);
			if(a[i]!=res-1)return false;
		}
	}
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if(m==1){
		int ma=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ma=max(ma,a[i]);
		}
		cout<<ma;
	}else if(m==n){
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==1){
				ans=a[i];
			}else{
				ans&=a[i];
			}
		}
		cout<<ans;
	}else if(n<=20){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(0,0);
		cout<<answer;
	}else if(m==n-1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			s1[i]=s1[i-1]&a[i];
			if(i==1)s1[i]=a[i];
		}
		for(int i=n;i>=1;i--){
			s2[i]=s2[i+1]&a[i];
			if(i==n)s2[i]=a[i];
		}
		int hhh=0;
		for(int i=2;i<=n-1;i++){
			hhh=max(hhh,s1[i-1]&s2[i+1]);
		} 
		hhh=max(hhh,s1[n-1]);
		hhh=max(hhh,s2[2]);
		cout<<hhh;
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(check()){
			for(int i=1;i<=n;i++){
				tong[a[i]]++;
			}
			if(tong[4]>=m){
				cout<<4;
			}else if(tong[3]+tong[4]>=m){
				cout<<3;
			}else if(tong[3]+tong[4]+tong[1]>=m){
				cout<<3;
			}else if(tong[4]+tong[3]+tong[2]>=m){
				cout<<2;
			}else{
				cout<<1;
			}
		}else{
			if(check2()){
				sort(a+1,a+n+1);
				int ans=a[n],j=m-1;
				for(int i=n-1;i>=1;i--){
					if(j==0)break;
					ans&=a[i];
					j--;
				}
				cout<<ans;
			}else{
				sort(a+1,a+n+1);
				int ans;
				int j=m;
				for(int i=n;i>=1;i--){
					if(i==n)ans=a[i];
					else ans&=a[i];
					//cerr<<ans<<endl;//qwq
					j--;
					if(j==0)break;
				}
				cout<<ans;
			}
			
		}
		
	}
	return 0;
} 
