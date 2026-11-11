#include<bits/stdc++.h>
using namespace std;
const int N=200005;
string s[N];
long long ans,n,m,sum[40];
int main()
{
	freopen("and.in","r",stdin);
   	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	long long x;
	for(int i=1;i<=n;i++){
		cin>>x;
		while(x){
			s[i]+=char(x%2+'0');
			x/=2;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<s[i].size();j++){
			if(s[i][j]=='1') sum[j]++;
		}
	}
	int maxn=-1;
	for(int i=30;i>=0;i--){
		if(sum[i]>=m){
			maxn=i;
			break;
		}
	}
	if(maxn==-1){
		cout<<0;
		return 0;
	}
	ans+=pow(2,maxn);
	while(1){
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++){
			if(s[i][maxn]=='1'){
				for(int j=0;j<s[i].size();j++){
					if(s[i][j]=='1') sum[j]++;
				}
			}else{
				s[i]="";
			}
		}
		int tp=maxn;
		for(int i=maxn-1;i>=0;i--){
			if(sum[i]>=m){
				maxn=i;
				break;
			}
		}
		if(maxn==tp) break;
		ans+=pow(2,maxn);
	}
	cout<<ans;
	return 0;
}
