#include<bits/stdc++.h>
using namespace std;
map<long long,long long> mp;
long long n,m,a[500010],midx,k,ans;
double mid,minn=1e12+1;
bool cmp(long long x,long long y){
	return x<y;
}
long long f(long long m,long long x,long long k){
	long long res=0;
	k--;
	while(m>0&&k>0){
		long long diff=x-a[k],g=mp[a[k]];
		if(m>=g*diff){
			m-=g*diff;
			res+=g;
		}
		else{
			while(m>0&&g>0){
				m-=diff;
				g--;
				if(m>0){
				res++;
				}
			}
		}
		k--;
	}
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	mid=m;
	int j=0;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		if(mp[x]==0){
			a[++j]=x;
		}
		mp[x]++;
		mid+=x;
	}
	mid/=n;
	sort(a+1,a+j+1,cmp);
	for(int i=1;i<=j;i++){
		if(mid>=a[i]&&a[i+1]>=mid){
			cout<<max(f(m,a[i],i)+mp[a[i]],f(m,a[i+1],i+1)+mp[a[i+1]]);
			break;
		}
	}
	return 0;
} 

