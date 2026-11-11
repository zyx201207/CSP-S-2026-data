#include<bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define PII pair<ll,ll>
#define pb push_back
#define lowbit(x) x&(-x)
using namespace std;
const int N=1e6+10;
const int INF=0x3f3f3f3f;
ll n,m,a[N],b[N],sum[N],ans,tot,num;
bool flag=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)flag=0;
	}
	if(flag){
		ll cnt=0;
		num=1;
		for(int i=1;i<=n;i++){
			cnt+=num;
			if(cnt>m){
				cout<<num;
				exit(0);
			}else{
				num++;
			}
		}
	}
	sort(a+1,a+n+1);
	flag=1;
	for(int i=2;i<=n;i++){
		b[++tot]=(a[i]-a[i-1]);
//		cout<<b[tot]<<" ";
		if(tot>=2){
			if(b[tot]!=b[tot-1]){
				flag=0;
			}
		}
	}
	if(flag){
		ll cnt=0;
		num=1;
		for(int i=1;i<=n;i++){
			cnt+=num*(b[2]-b[1]);
			if(cnt>m){
				cout<<num;
				exit(0);
			}else{
				num++;
			}
		}
	}
//	cout<<endl;
	for(int i=1;i<=tot;i++){
		sum[i]=sum[i-1]+b[i];
//		cout<<sum[i]<<" ";
	}
//	cout<<endl;
	if(n<=10000){
		for(int i=2;i<=n;i++){
			ll cnt=0,l=0;
	//		cout<<"当前是第"<<i<<"个宝石\n";
			for(int j=1;j<i;j++){
				cnt+=sum[i-1]-sum[i-j-1];
	//			cout<<"前面"<<j<<"个都变成现在这个需要"<<cnt<<endl;
				l=j; 
				if(cnt>m){
					l--;
					break;
				}
			}
			ans=max(ans,l+1);
		}
	}else{
		ll cnt=1,l=1;
		for(int i=1;i<=tot;i++){
	//		cout<<cnt<<" "<<b[i]<<endl;
			if(cnt*b[i]<=m){
				m-=(cnt*b[i]);
				cnt++;
			}else if((cnt-1)*b[i]<=m+(sum[i-1]-sum[l-1])){
				m+=(sum[i-1]-sum[l-1]);
				l++;
			}else{
				cout<<cnt;
				exit(0);
			}
	//		cout<<m<<endl;
		} 
		cout<<cnt;
		exit(0);
	}
	cout<<ans;
}
/*
我连T1都AC不了
但是我好像没有明年了... 
AFO吧... 
再见了，各位 
*/ 
