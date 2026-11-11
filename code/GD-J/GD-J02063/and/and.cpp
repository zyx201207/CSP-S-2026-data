//´ò60·Ö±©Á¦
//is dp?
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+50;
int n,m,ans=0;
int qwq=0,awa=0;
int A=0,B=0;
int a[N],dp[N];
string str="00000000000000000000000000";
string str1="11111111111111111111111";
string s;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=4){
			qwq++;
			if(a[i]==4)awa++;
		}
		dp[i]=a[i];
		if(i>=2)dp[i]&=dp[i-1];
	}
	if(m==1){//6
		cout<<a[1];
		return 0;
	}if(n==m){//7
		cout<<dp[n];
	}if(m==2){//8~10
		int cnt=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=max(cnt,a[i]&a[j]);
			}
		}cout<<cnt;
		return 0;
	}if(qwq==n){//16,17
		if(awa>=m){
			cout<<4;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==3){
					m--;
					if(m==0){
						cout<<3;
						return 0;
					}
				}
			}for(int i=1;i<=n;i++){
				if(a[i]==2){
					m--;
					if(m==0){
						cout<<2;
						return 0;
					}
				}
			}for(int i=1;i<=n;i++){
				if(a[i]==1){
					m--;
					if(m==0){
						cout<<1;
						return 0;
					}
				}
			}cout<<0;
			return 0;
		}
	}if(A==n){//A
		sort(a+1,a+n+1);
		cout<<a[1];
		return 0;
	}
	return 0;
}
/*
5 3
31 3 1 15 7

4 2
3 15 12 12
*/
