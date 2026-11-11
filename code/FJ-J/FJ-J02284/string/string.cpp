#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[200005],n,l,sum,num;char a[200005];
void solve(){
	int i=0,j=n+1,k,ans=0;
	for(;;){
		if(sum<num){
			i++;
			if(sum+x[i]<num)k=x[i];
			else k=num-sum;
			sum=min(sum+x[i],l/2);
			if(a[i]!=a[j]&&j!=n+1)ans+=k;
		}else{
			j--;
			if(num+x[j]<sum)k=x[j];
			else k=sum-num;
			num=min(num+x[j],l/2);
			if(a[i]!=a[j]&&i!=0)ans+=k;
		}
		//cout<<ans<<" ";
		if(num==l/2&&sum==l/2)break;
	}
	cout<<ans;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>a[i];
		l+=x[i];
	}
	solve();
	return 0;
} 
