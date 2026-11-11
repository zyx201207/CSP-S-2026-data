#include <bits/stdc++.h>
using namespace std;
long long xxxx,zhong;
long long n=0,d=0,a[2000010],dp[2000010];
long long le[20010][10010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	
	cin>>xxxx>>zhong;
	
	for(int c=1;c<=zhong;c++){
		cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int l=0,mm=0;
				mm=a[j]-a[i];
				while(true){
					l+=d;
					le[i][j]++;
					mm-=d;
					if(mm<=d){
						le[i][j]++;
						break;
					}
				}
			}
			
		}
		
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				cout<<le[i][j]*1<<" ";
			}
			cout<<"\n";
		}
		
		
		
		if(n<3)cout<<0<<"\n";
		if(d==1)cout<<0<<"\n";
	}
	
	
	return 0;
}

