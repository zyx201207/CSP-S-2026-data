#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long s[500005];
long long cnts[500005];
struct node{
	long long val,cnt;
}b[500005];
int p;
map<long long,bool>mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(!mp[a[i]]){
			mp[a[i]]=1;
			b[++p].cnt=1;
			b[p].val=a[i];
		}
		else{
			b[p].cnt++;
		}
	}
	long long ans=b[1].cnt;
	for(int i=1;i<=p;i++){
		//cout<<b[i].val<<" "<<b[i].cnt<<"\n";
		
		s[i]=s[i-1]+b[i].cnt*b[i].val;
		cnts[i]=cnts[i-1]+b[i].cnt;
		//cout<<s[i]<<" "<<cnts[i]<<"\n";
	}
	for(int i=2;i<=p;i++){
		int l=1,r=i,mid,cp=i;
		while(l<=r){
			mid=l+r>>1;
			if(b[i].val*(cnts[i]-cnts[mid-1])-(s[i]-s[mid-1])<m){
				cp=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		cp--;
		//cout<<i<<" "<<cp<<endl;
		//cout<<endl<<endl<<endl;
		if(cp<1){
			ans=max(ans,cnts[i]);
			//cout<<i<<" "<<ans<<" "<<cnts[i]<<"\n";
		}
		else{
		//	cout<<i<<endl;
		//	cout<<cnts[i]-cnts[cp]<<"\n";
		//	cout<<m<<" "<<s[i]-s[cp]<<" "<<b[i].val<<"\n";
		//	cout<<m-b[i].val*(cnts[i]-cnts[cp])-(s[i]-s[cp])<<"\n";
		//	cout<<b[i].val-b[cp].val<<"\n";
		//	cout<<"\n";
			ans=max(ans,cnts[i]-cnts[cp]+(m-(b[i].val*(cnts[i]-cnts[cp])-(s[i]-s[cp])))/(b[i].val-b[cp].val));
		}
	}
	cout<<ans;
	return 0;
}
