#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
const int N=2e6+5;
int a[N];
bool check(int x,int y){
	int k=0;
	for(int i=x+1;i<y;i++){
		if(a[i]-a[x]<=d&&a[y]-a[i]<=d) k++;
	}
	if(k==2) return true;
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
        for(int i=1;i<n;i++){
        	for(int j=i+1;j<=n;j++){
        		if(check(i,j)) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
