#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e5+10;
ll n,a[maxn],q[maxn],cnt=0,num=0,sum=0,ans=0;
string s;
char c[maxn],p[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	ans=cnt;
	cnt/=2;
	for(ll i=1;cnt>0;i++){
		if(cnt>=a[i])cnt-=a[i],q[++sum]=a[i],p[sum]=c[i];
		else q[++sum]=a[i]-cnt,cnt=0,p[sum]=c[i],a[i]-=q[sum];
	}
	for(ll i=n,j=1;i>=0&&j<=ans;){
		if(c[i]==p[j]){
			if(a[i]>=q[j])a[i]-=q[j],j++;
			else num+=a[i],q[j]-=a[i],i--;
		}else{
			if(a[i]>=q[j])num+=q[j],a[i]-=q[j],j++;
			else num+=a[i],q[j]-=a[i],i--;
		}
	}
	cout<<num;
	return 0;
}
