#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,sum,summ,arr[500010],dd[500010];
int main(){
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			dd[i]=arr[i]-arr[i-1];
		}
		if(c==11||c==12){
			long long mid=arr[2]-arr[1];
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(!(arr[j]-arr[i]>d&&arr[j]-arr[i]<=2*d)) continue;
					sum++;
				}
			}
		}
		if(c==13||c==14){
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(arr[j]-arr[i]<=d) continue;
					if(arr[j]-arr[i]>d&&arr[j]-arr[i]<=2*d) sum++;
				}
			}
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
