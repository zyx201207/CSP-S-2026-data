//特判拿30+贪心拿45=75？ 
//csp RP++ !!!
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxn,maxout=1;
bool pdb=1,pda=1;//判断特A和特B
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			pdb=0;
		}
		if(a[i]!=i){
			pda=0;
		}
		maxn=max(a[i],maxn);
	}
	if(pdb||(pda)){
		long long x=(n*a[n]-n*a[1])/2;;
		if(m>=x){
			cout<<n;
			return 0;
		}
		else{
			int i=n;
			while(x>m){
				x-=(a[n]-a[i]);
				i--;
			}
			cout<<n-i;
			return 0;
		}
	}
	//贪心
	sort(a+1,a+n+1);
	for(int i=n;i>1;i--){
		if(i<maxout){
			break;
		}
		long long hf=0,cnt=0;
		for(int j=i;j>=1;j--){
			if(a[i]-a[j]+hf>m){
				break;
			}
			else{
				cnt++;
				hf+=(a[i]-a[j]);
			}
		}
		maxout=max(maxout,cnt);
	}
	cout<<maxout;
	return 0;
}
