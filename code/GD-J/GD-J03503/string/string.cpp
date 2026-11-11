#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll n,a;char c[N];ll b[N],len,sum,cnt;
void dfs(ll j){
	if(cnt<=1) {
		return;
	}
	if(b[j]<b[n]){
		if(c[j]!=c[n]) sum+=b[j];
		b[n]-=b[j];j+=1;cnt--;
		dfs(j);
	}else if(b[j]==b[n]){
		if(c[j]!=c[n]) sum+=b[j];
		cnt-=2;n-=1;j++;
		dfs(j);
	}else{
		if(c[j]!=c[n]) sum+=b[n];
		b[j]-=b[n];
		n--;cnt--;dfs(j);
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;cnt=n;
	for(ll i=1;i<=n;i++){
		cin>>a>>c[i];
		b[i]=a;len+=a;
	}
	dfs(1);
	cout<<sum;
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
