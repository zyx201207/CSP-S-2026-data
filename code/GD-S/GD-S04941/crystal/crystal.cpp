#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
long long n,m;
long long power[N];
long long dp[N];
long long s[N],a[1001][1001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>power[i];
	}
	sort(power+1,power+n+1);
	for(int i=1;i<=n;i++){
		s[i]=power[i]-power[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j;k>=i+1;k--){
				a[i][j]+=power[j]-power[k-1];
			}
		}
	}
	int cnt=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			if(a[j][j+i]<=m){
				cnt++;
				break;
			}
		}
	}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
