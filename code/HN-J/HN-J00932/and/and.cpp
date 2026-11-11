#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans,cnt;
	string a; 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
	}
	for(int i=0;i<m;i++){
		for(int j=i+1;j<=n;j++){
			for(int h=j+1;i<=n;h++){
				ans=ans and h;
			}
			ans=ans and j;
		}
		ans=i and i;
	}cout<<ans;
	return 0;
	}

