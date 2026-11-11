#include<bits/stdc++.h>
using namespace std;
vector<int> num[200005];
int n,m,a,b[200005],c[200005];
int dp[200005];
int f(int j,int i){
	vector<int> x;
	int y=dp[j],z=0;
	while(y>0){
		x.push_back(y%2);
		y=y/2;
	}
	int l=x.size();
	for(int k=0;k<min(b[i],l);k++){
		if(x[k]==1 && num[i][k]==1){
			x[k]=1;
		}else{
			x[k]=0;
		}
	}
	z=1;
	long long ans=0;
	for(int k=0;k<l;k++){
		if(k!=0){
			z=z*2;
		}
		if(x[k]==1) ans+=z;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		c[i]=a;
		while(a>0){
			num[i].push_back(a%2);
			a=a/2;
			b[i]++;
		}
	}
	sort(num,num+n+1);
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(j-1==0){
				dp[1]=max(dp[1],c[i]);
			}
			dp[j]=max(dp[j],f(j,i));	
		}
	}
	cout<<dp[m];
	return 0;
}
