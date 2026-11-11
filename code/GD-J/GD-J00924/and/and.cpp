#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<=b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
const int N=1e6+10;
ll n,m,ar[N],dp[N][50],ans;
bool f[N][50],f1[N],f2[N],num[50];
string str[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	f(i,1,n){
		str[i]="";
		cin>>ar[i];
	    ll op=ar[i];
		while(op){
			if(op%2==1)str[i]=str[i]+'1';
			else str[i]=str[i]+'0';
			op/=2;
		}
		ll s=str[i].size()-1;
		f(j,0,s){
			if(str[i][j]=='1')f[i][j]=1;
		}
	}
	ll pos=0,id=0;
	f_(j,30,0){
		ll op=0;
		f(i,1,n){
			if(f[i][j]){
				op++;
				f1[i]=1;
			}		
		}
	    if(op>=m){
	    	num[j]=1;
	    	id=j;
	    	break;
		}else{
			f(i,1,n)f1[i]=0;
		}
	}
	ll x=id;
	f_(j,x-1,0){
		ll op=0;
		f(i,1,n){
			if(f[i][j]&&f1[i]){
				op++;
				f2[i]=1;
			}
		}
		if(op>=m){
			num[j]=1;
			f(i,1,n){
				f1[i]=f2[i];
				f2[i]=0;
			}
		}else{
			f(i,1,n)f2[i]=0;
		}
	}
	ll k=1;
	f(i,0,30){
		if(num[i])ans+=k;
		k*=2;
	}
	cout<<ans;
	return 0;
}
