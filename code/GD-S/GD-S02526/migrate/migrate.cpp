#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,cnt=0;
		cin>>n>>d;
		vector<int>x(n);
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		if(1<=c<=10){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(abs(x[i]-x[j]>=d)){
						cnt++;
					}
				}
			}
			cout<<cnt;
		}
		else if(c==11||c==12){
			if(abs(x[1]-x[0])>d){
				cout<<0;
			}
			else{
				int max=d/abs(x[1]-x[0]);
				cout<<max*(n/2+1);
			}
		}
		else{
			cout<<n-1;
		}
	}
	return 0;
}
