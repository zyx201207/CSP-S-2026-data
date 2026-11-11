#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
int a[maxn],b[maxn],u[maxn];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n;
	scanf("%lld",&n);
	int cnt=0;
	for(int i=1;i<=n;i++){
		char c;
		
		scanf("%lld",&a[i]);
		cnt+=a[i];
		cin>>c;
		int j=c-'a';
		b[i]=j;
	}
	
	int cnt2=0,ans=0;
	int j=n;
	cnt=cnt/2;
	for(int i=1;i<=n,cnt2<=cnt;i++){
		
		int num=a[i];
		if(cnt2+a[i]>cnt){
			num=cnt-cnt2;
			cnt2=cnt+1;
		}
		else{
			cnt2+=a[i];
		}
		
		while(num){
			int uj=a[j]-u[j];
			if(b[j]==b[i]){
				if(num>uj){
					num-=uj;
					j--;
				}
				else{
					
					u[j]+=num;
					num=0;
				}
				continue;
			}
			if(num>uj){
				num-=uj;
				ans+=uj;
				j--;
			}
			else{
				ans+=num;
				u[j]+=num;
				num=0;
			}
		}
	}
	
	printf("%lld",ans);
}
