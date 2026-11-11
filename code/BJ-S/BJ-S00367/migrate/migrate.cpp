#include<bits/stdc++.h>
using namespace std;
int n,d;
int c,t;
const int N=2e6+5;
int a[N];
bool as(int x,int y){
	int b=d,w=1,l=x;
	for(int i=x+1;i<=y;i++){
		if(b>=a[i]-a[l]){
			b-=a[i]-a[l];
			l=i;
		}else{
			w++;
			b=d;

		}
	}

	if(w==1)return 0;
	if(w==2)return 1;
	return 0;
  }

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>c>>t;

	while(t--){
		cin>>n>>d;
		int ans=0,i1=n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>a[i-1]+d){
				i1=i-1;
				break;
			}
		}
		for(int i=1;i<=i1-3;i++){
			int j=i+3;
			if(as(i,j)){
				ans++;
			
				}
		}
		cout<<ans<<endl;			
	}
	return 0;
}
