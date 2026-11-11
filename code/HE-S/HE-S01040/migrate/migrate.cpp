#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll c,T,n,d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		x[n+1]=4e18;
		x[0]=-4e18;
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				/*if((j-i)%2==0){
					int mid=(j-i)/2;
					if(x[i]-x[mid]<=d&&x[mid]-x[j]<=d) continue;
				}*/
				vector<int> op1,op2;
				op1.push_back(i);
				int pt=i,dis=0;
				while(pt<j){
					while(dis+x[pt+1]-x[pt]<=d){
						dis+=x[pt+1]-x[pt];
						pt++;
						if(pt>=j) break;
					}
					if(x[pt+1]-x[pt]>d) break;
					if(pt>=j) break;
					dis=0;
					op1.push_back(pt);
				}
				op1.push_back(j);
				op2.push_back(j);
				pt=j,dis=0;
				while(pt>i){
					while(dis+x[pt]-x[pt-1]<=d){
						dis+=x[pt]-x[pt-1];
						pt--;
						if(pt<=i) break;
					}
					if(x[pt]-x[pt-1]>d) break;
					if(pt<=i) break;
					dis=0;
					op2.push_back(pt);
				}
				op2.push_back(i);
				/*for(int x : op1) cout<<x<<' ';
				cout<<'\n';
				for(int x : op2) cout<<x<<' ';
				cout<<'\n';
				cout<<'\n';*/
				ll cnt=0;
				if(op1.size()!=op2.size()) continue;
				int pos=-1;
				for(int k=0;k<op1.size();k++){
					if(op1[k]!=op2[op2.size()-k-1]){
						cnt++;
						pos=k;
					}
				}
				if(cnt==1){
					if((i-j)%2==0){
						int pos2=op2.size()-pos-1;
						int mid=(op1[pos]+op2[pos2])>>1;
						if(mid!=op1[pos]&&mid!=op2[pos]){
							if(x[mid]-x[op1[pos-1]]<=d&&x[op2[pos2+1]]-x[mid]<=d) continue;
						}
					}
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
