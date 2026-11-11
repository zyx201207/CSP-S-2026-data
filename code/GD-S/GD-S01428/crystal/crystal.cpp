#include<bits/stdc++.h>
#define int long long
#define f(i,x,n,y) for(int i=x;i<=n;i+=y)
#define f1(i,x,n,y) for(int i=x;i>=n;i-=y)
#define pair pair<int,int>
using namespace std;
const int N=5e5+5;
int n,m,m1,a[N],b[N],k,ans,sum,cnt,t;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false); 
	cin>>n>>m,m1=m;
	f(i,1,n,1){
		cin>>a[i];
	}
	cnt=a[2]-a[1];
	f(i,3,n,1){
		if(a[i]-a[i-1]!=cnt){
			t=1;
		}
	}
	sort(a+1,a+1+n);
	if(!t&&n>=100000){
		f1(j,n,1,1){
			m=m-(a[n]-a[j]);
			if(m<0){
				break;
			}
			ans++;
		}
		return cout<<ans,0;
	}
	f(i,1,n,1){
		ans=0,m=m1;
		f1(j,i,1,1){
			m=m-(a[i]-a[j]);
			if(m<0){
				break;
			}
			ans++;
		}
		sum=max(sum,ans);
	}
	cout<<sum;
	
	
	return 0;
} 
