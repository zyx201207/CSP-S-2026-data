#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int a[N],s[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t,sum=0;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<+n;i++){
			cin>>a[i];
			s[i]=a[i]-a[i-1];
		}
		for(int l=1;l<n-3;l++){
			for(int r=4;r<=n;r++){
				if(a[r]-a[l]<=d){
					sum++;
				}
			}
		}
		cout<<sum;
	}
	return 0;
} 
