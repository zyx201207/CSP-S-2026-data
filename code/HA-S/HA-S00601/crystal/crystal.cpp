#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0,cnt=1;
int a[500005];
bool vis[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	if(n>=3){
		
		sum+=a[1];
		sum+=a[2];
		for(int i=3;i<=n;i++){
			if((sum+m)/(i-1)==a[i]){
				int ans=0;
				
				if((sum+a[i]+m)/(i)==a[i+1]){
					for(int j=i+1;j<=n;j++){
						if(a[i]==a[j]) ans++;
					}
					
				}
				cnt=ans+i;
				break;
			}
			
			if((sum+m)/(i-1)>a[i]){
				vis[i]=1;
				sum+=a[i];
				continue;
			}
			sum+=a[i];
			
			if((sum+m)/(i-1)<a[i]&&vis[i-1]==1){
				cnt=i-1;
				break;
			}
		}
		
		
	}
	
	if(n==2){
		if((a[1]+m)/2>=a[2]) cnt=2;
		else cnt=1;
	}
	
	if(n==1) cnt=1;
	
	cout<<cnt;
	return 0;
}
