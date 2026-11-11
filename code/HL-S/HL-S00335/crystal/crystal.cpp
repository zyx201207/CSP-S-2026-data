#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long a[MAXN],sum,s[MAXN];
long long n,m;
bool pd(int gs,long long x){
	//gs记录个数 x记录平均值
	for(int i=gs;i>=1;i--){
		if(a[i]>x) return false;
	}
	if(x*gs-s[gs]>m) return false;
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	long long gc=a[2]-a[1];
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		if(i>2){
            if(a[i]-a[i-1]!=gc){
                flag=false;
            }
		}
	}
	if(flag){
            long long ans=1,zs=0;
        while(1){
            if(zs+ans*gc>=m){
                cout<<ans-1;
                return 0;
            }
            else{
                zs+=ans*gc;
                ans++;
            }
        }
	}
	sum+=m;
	for(int i=n;i>=1;i--){
		long long sum1=s[n]-s[i-1];
		sum1=sum-sum1;
		long long av=floor(sum1*1.0/(i-1));
		if(pd(i-1,av)){
			cout<<i-1;
			break;
		}
	}
	return 0;
}
