#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[500005],b[500005];
int n;
long long m;
int solve(int l){
	long long cnt=m;
	int idx=l,ans=1;
	while(idx<n){
		long long need=idx*b[idx];
		if(cnt>=need){
			cnt-=need;
			ans++;
			idx++;
		}
		else{
			break;
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	cin>>a[1];
	bool flaga=true;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]) flaga=false;
	}
	if(flaga){
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	bool flagb=true;
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		if(b[i]!=b[i-1]) flagb=false;
	}
	if(flagb){
		long long cnt=m;
		int idx=1,ans=1;
		/*while(1){
			long long need=idx*b[idx];
			if(cnt>=need){
				cnt-=need;
				ans++;
				idx++;
			}
			else{
				break;
			}
		}
		cout<<ans;
		return 0;*/
		cout<<solve(1);
		return 0;
	}
	int len=1,sum=1;
	unsigned long long cost=0;
	for(int i=1;i<n;i++){
		/*if(cost+b[i]*len>m){
			cost=0;	
			len=1;	
		}
		else{
			cost+=b[i]*len;
			len++;
		}
		sum=max(sum,len);*/
		sum=max(sum,solve(i));
	}
	cout<<sum;
	return 0;
}
