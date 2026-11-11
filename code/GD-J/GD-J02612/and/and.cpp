#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int a[N],M=31;
long long ans=0,Ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	while(M--){
		int cnt=0;
		Ans=ans;
		ans|=1<<M;
		//cout<<"ans:"<<ans<<' ';
		for(int i=1;i<=n;i++){
			int t=a[i]&ans;
			//cout<<t<<' ';
			if(t==ans){
				//cout<<"Yes!";
				cnt++;
			}
			if(cnt>=m){
				break;	
			}
		}
		if(cnt<m) ans=Ans;
		//else Ans&=ans;
		//cout<<ans<<' ';	
		//cout<<'\n';	
	}
	cout<<ans;
	return 0;
}
