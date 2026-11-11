#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ovo ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define N 500050
ll n,m,num,tot;
ll a[N];
struct Q{
	ll cnt,val,id;
}b[N];
int main(){
	ovo;
	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	num=1;
	tot=1;
	int i=2;
	b[1].id=1;
	while(i<=n+1){
		if(a[i]==a[i-1])num++,i++;
		else{
			b[tot].val=a[i-1];
			b[tot+1].id=i;
			b[tot].cnt=num;
			tot++;
			num=1;
			i++;
		}
	}
//	for(int i=1;i<tot;i++)cout<<b[i].val<<' '<<b[i].cnt<<' '<<b[i].id<<endl;//check people
	int ans=0,anss=0;
	for(int i=1;i<tot;i++){
		ll k=m;
		anss=1;
		int idk=b[i].id;
		ll w=b[i].val;
//		cout<<b[i].val<<' '<<b[i].cnt<<' '<<b[i].id<<endl;
		int j=1;
		while(k){
			if((w-a[idk-j])<=k&&(idk-j)>0){
				anss++;
				k-=(w-a[idk-j]);
				j++;
//				cout<<j<<' '<<k<<' '<<(idk-j)<<" "<<"jilu"<<endl;	
			}
			else break;
		}
		anss+=(b[i].cnt-1);
//		cout<<anss<<endl;
		ans=max(ans,anss);
	}
	cout<<ans<<endl;
	return 0;
}
