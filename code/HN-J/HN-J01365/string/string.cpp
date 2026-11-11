#include<bits/stdc++.h>
using namespace std;
struct abc{
	char ci;
	int ai;
}a[200010];
char x,y;
long long n,sum=1,ans,sum2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].ai>>a[i].ci;
		sum+=a[i].ai;
	}
	
	for(long long i=1,k=sum-1;i<=(sum-1)/2;i++,k--){
		sum2=0;
		for(int j=1;j<=n;j++){
			if(i<=sum2+a[j].ai&&i>sum2){
				x=a[j].ci;
				break;
			}
			sum2+=a[j].ai;
		}
		sum2=0;
		for(int j=1;j<=n;j++){
			if(k<=sum2+a[j].ai&&k>sum2){
				y=a[j].ci;
				break;
			}
			sum2+=a[j].ai;
		}
		
		if(x!=y) ans++;
	
	}
	cout<<ans;
	return 0;
} 
