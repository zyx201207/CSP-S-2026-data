#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mp[5000005];
ll noa=0;
ll non=0;
int ans=0;
ll c[5000005];
bool cmp(ll a,ll b){
	return a<b;
}
ll que(int s,int e){
	return c[e]-c[s]-(mp[e]-mp[s])*(s-1);
}
int main(){ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>non>>noa;
	for(int i=1;i<=non;i++){
		cin>>mp[i];
	}
	sort(mp+1,mp+1+non,cmp);
//	for(int i=1;i<=non;i++){
//		cout<<mp[i]<<" ";
//	}
	for(int i=1;i<=non;i++){
		c[i]=c[i-1]+((mp[i]-mp[i-1])*(i-1));
	}
//	for(int i=1;i<=non;i++){
//		cout<<c[i]<<" "<<endl;
//	}
//	for(int i=1;i<=noa;i++){
//		int a,b;
//		cin>>a>>b;
//		cout<<c[b]-c[a]-(mp[b]-mp[a])*(a-1)<<endl;
//	}
	int pa=1,pb=1;
	while(pa<=pb&&pb<=non){
		if(que(pa,pb)>noa){
			pa++;
		}else{
			ans=max(ans,pb-pa+1);
			pb++;
		}
	}
	cout<<ans;
} 
