#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int m,ans=0;
int l[500005];
int check(int u){
	int f=1;
	for(int j=u-1;j>0 && m!=0;j--){
		if(l[j]<=l[u]){
			//cout<<(m>=l[u]-l[j])<<" "<<l[u]<<endl;
			if(m>=l[u]-l[j]){
				m=m-(l[u]-l[j]);
				f++;
				//cout<<12<<endl;
			}
			else{
				break;
			}
		}
	}
	if(f>=ans){
		ans=f;
		return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int md=m;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	sort(l+1,l+n+1);
	int le=1,ri=n;
	while(le<=ri){
		m=md;
		int mid=(le+ri)/2;
		if(check(mid)){
			//cout<<13;
			le=mid+1;
		}
		else{
			ri=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
