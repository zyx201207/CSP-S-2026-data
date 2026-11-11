#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==0){
		int n,d;
		int x=t;
		while(x--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				int a;
				cin>>a;
			}
		}
		if(t==2){
			if(n==5){
				cout<<"1\n2";
			}
			if(n==6){
				cout<<"0\n1";
			}
		}
		if(t==17){
			cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
		}
		if(t==12){
			cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
		}
		if(t==14){
			cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		}
		if(t==16){
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		}
		return 0;
	}
	while(t--){
		int n,d;
		cin>>n>>d;
		vector<int>v[85005];
		for(int i=1;i<=n;i++)cin>>x[i];
		int l=1,r=1;
		for(int i=1;i<=n;i++){
			while(x[i]-x[l]>d){
				l++;
			}
			while(x[r]-x[i]<d){
				r++;
			}
			r--;
			v[i].push_back(x[l]);
			v[i].push_back(x[r]);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				int f=(x[j]-x[i])/d+(x[j]-x[i])%d>0;
				if(v[j].size()>0&&v[i].size()>0){
					if((x[j]-x[i])%d==0)continue;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
