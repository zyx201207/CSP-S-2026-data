#include<bits/stdc++.h>
#define ll long long 
const int N=1e5+5;
using namespace std;
ll a[N*5];int n,m;
void cs1_9(){
	int maxn=0;
	for(int i=1;i<=n;i++){
		int k=0,sum=1;
		for(int j=i-1;j>=1;j--){
			if(m>=a[i]-a[j]+k){
				k+=a[i]-a[j];
				sum++;
			}else{
				break;
			}
		}
		maxn=max(maxn,sum);
	}
	cout<<maxn;
}
void csAB(int cz){
	ll k=1;int i;
	for(i=1;;i++){
		if(k<m/i){
			k*=i;
		}else{
			break;
		}
	}
	cout<<i;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=2){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				flag=0;
			}
		}
	}
	int cz=a[2]-a[1];
	sort(a+1,a+1+n);
	if(flag)csAB(cz);
	else cs1_9();
	return 0;
}//暴力+特殊性质50分 
