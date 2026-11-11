#include<bits/stdc++.h>
using namespace std;

int c,_,n;

long long d,arr[5123456];

int frthr[5123456];

int rfthr[5123456];

int mans[5123456];

bool vis[5123456];

void sol(){
	memset(rfthr,0,sizeof rfthr);
	memset(frthr,0,sizeof frthr);
	memset(arr,0,sizeof arr);
	memset(mans,0,sizeof mans);
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		rfthr[i]=i;
	}
	if(c==0||c==12||c==11){
		long long cha=arr[2]-arr[1];
		if(cha>=d||d%cha==0){
			cout<<0<<"\n";
			return;
		}
		int times=d/cha+1;
		cout<<n-times+1<<"\n";
		return;
	}
	for(int i=1;i<=n;i++){
		frthr[i]=(int)(lower_bound(arr+1,arr+1+n,arr[i]+d)-arr);
		if(arr[frthr[i]]!=arr[i]+d)frthr[i]--;
		rfthr[i]=(int)(lower_bound(arr+1,arr+1+n,arr[i]-d)-arr);
		if(arr[rfthr[i]]!=arr[i]-d)rfthr[i]++;
	}
	//for(int i=1;i<=n;i++){
	//	cout<<frthr[i]<<" "<<rfthr[i]<<"\n";
	//}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(frthr[i]==i){
			continue;
		}
		mans[i]=0;
		for(int j=frthr[i]+1;j<=frthr[frthr[i]];j++){
			if(rfthr[j]==j){
				break;
			}
			if(rfthr[j]==frthr[i]-1){
				mans[i]++;
			}
		}
	}
	memset(vis,0,sizeof vis);
	//for(int i=1;i<=n;i++){
	//	cout<<mans[i]<<" ";
	//}
	//cout<<"\n";
	for(int i=1;i<=n;i++){
		if(vis[i]){
		//	cout<<i<<"->\n";
			continue;
		}
		int now=i;
		int cnt=1;
		int hans=0;
		while(!vis[now]){
			vis[now]=true;
			hans+=cnt*mans[now];
		//	cout<<"^"<<hans<<"\n";
			now=frthr[now];
			cnt++;
		}
		//cout<<i<<": "<<ans<<" "<<hans<<"\n";
		ans+=hans;
	}
	int sum=0;
	for(int i=n;i>=1;i--){
		if(rfthr[i]==i){
			continue;
		}
		mans[i]=0;
		for(int j=rfthr[i]-1;j>=rfthr[rfthr[i]];j--){
			if(frthr[j]==j){
				break;
			}
			if(frthr[j]==rfthr[i]+1){
				mans[i]++;
			}
		}
	}
	memset(vis,0,sizeof vis);
	//for(int i=1;i<=n;i++){
	//	cout<<mans[i]<<" ";
	//}
	//cout<<"\n";
	for(int i=n;i>=1;i--){
		if(vis[i]){
		//	cout<<i<<"->\n";
			continue;
		}
		int now=i;
		int cnt=1;
		int hans=0;
		while(!vis[now]){
			vis[now]=true;
			hans+=cnt*mans[now];
		//	cout<<"^"<<hans<<"\n";
			now=rfthr[now];
			cnt++;
		}
		ans+=hans;
	}
	cout<<ans<<"\n";
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>_;
	while(_--){
		sol();
	}
	return 0;
}
