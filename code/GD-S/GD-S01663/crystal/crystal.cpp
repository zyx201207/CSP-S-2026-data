#include<bits/stdc++.h>
using namespace std;
long long n,m,ma,p,p2,num,sum,k,ma2=-1e9,mi2=1e9,a[1001010];
map<int,long long>mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)p=1;
		if(i>=3&&(a[i]-a[i-1]!=a[i-1]-a[i-2]))p2=1;
		ma2=max(ma2,a[i]);
		mi2=min(mi2,a[i]);
	}
	if(ma2<=100&&mi2>=-100){
		for(int i=1;i<=n;i++)mp[a[i]]++;
		for(int i=1;i<=n;i++){
			long long g=m,num=0;
			for(int j=a[i];j>=-100;j--){
				if(mp[j]==0)continue;
				int sum=a[i]-j;
				if(g>=sum*mp[j]){
					g-=sum*mp[j];
					num+=mp[j];
				}else{
					num+=g/sum;
					break;
				}
			}
			ma=max(ma,num);
		}
		cout<<ma;
		return 0;
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	if(p==0){
		k=1;
		while(m>=k){
			m-=k;
			k++;
		}
		cout<<min(n,k);
	}else if(p2==0){
		int q=a[2]-a[1];
		num=0,k=2,sum=q;
		while(m>=sum){
			sum+=k*sum;
			num++;
			k++;
		}
		cout<<min(n,num+1);
	}else{
		for(int i=1;i<=n;i++){
		long long num=0,p=0;
			for(int j=i-1;j>=1;j--){
				num+=a[i]-a[j];
				if(num<=m)p=j;
				else break;
			}
			ma=max(ma,i-p+1);
		}
		cout<<ma;
	}
	return 0;
}
