#include<bits/stdc++.h>
using namespace std;
#define ll  long long
ll power[500007];
ll cha[500007];
ll tot[500007];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>power[i];
	}
	sort(power,power+n);
	for(int i=1;i<n;i++){
		cha[i-1]=power[i]-power[i-1];
	}
	if(m==0){
		ll cnt=0,ans=0;
		for(int i=0;i<n-1;i++){
			if(cha[i]==0){
				cnt++;
			}else{
				ans=max(ans,cnt);
				cnt=0;
			}
		}ans=max(ans,cnt);
		ans+=1;
		cout<<ans<<endl;
		return 0;
	}
	tot[n-1]=0;
	tot[n-2]=cha[n-2];
	for(int i=3;i<=n;i++){
		tot[n-i]=tot[n-i+1]+cha[n-i];
	}
	ll step=m;
	ll aans=0,k=0;
	ll lin;
	for(int i=n-1;i>=0;i--){
		int j=i;
		lin=tot[i-1];
		while(step>0&&j>=0){
			if(step-tot[j]>=0){								
				k++;
				step-=tot[j];
				tot[j]-=lin;
				j--;
				aans=max(aans,k);
			}
			else break;
		}
		step=m;
		k=0;
		for(int l=j;l>=0;l--){
			tot[l]-=lin;
		
			
		}
	}
	cout<<aans<<endl;
	
	return 0;
	
}
