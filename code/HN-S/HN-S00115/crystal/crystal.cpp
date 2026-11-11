#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m;
int a[200005],b[200005],ans,maxx,x,y;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	cin>>n>>m;
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2){
			if(a[i]-a[i-1]!=a[2]-a[1]){
				flag=1;
			}
		}
	}
	if(flag=0){
		cout<<min(m/(a[2]-a[1]),n);
		return 0;
	}
	for(int i=1;i<=n;i++){
	//	cout<<a[i]<<" "<<a[i-1]<<" "<<abs(a[i]-a[i-1])<<endl;
		b[i]=b[i-1]+abs(a[i+1]-a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(b[j]-b[i])<=m){
				
				int ans2=(j-i+1);
		
				if(maxx<ans2){
					x=i;
					y=j;
					maxx=ans2;
					ans=b[j]-b[i];
				}
				//maxx=max(maxx,ans2);
			}
		}
	}

	cout<<maxx;
}
