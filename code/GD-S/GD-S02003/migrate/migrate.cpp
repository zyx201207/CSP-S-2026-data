#include<bits/stdc++.h>
#define int long long

using namespace std;

int c,T,n,d;
const int N = 2000010;
int dp[N],a[N],pos[N];
int v[N],t[N],s[N];
int cha;

signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			pos[i]=dp[i]=t[i]=0;
		}
		
		if(c>=11&&c<=12){
			cha=a[2]-a[1];
			if(d<=cha){
				cout<<"0\n";
			}else{
				if((cha+1)/2>d){
					cout<<"0\n";
				}else{
					int k=(d+cha-1)/cha*2-1;
					cout<<max(n-k,0ll)<<'\n';
				}
			}
			continue;
		}
		if(c>=13&&c<=14){
			cout<<"0\n"; 
		}
		
		int now=1;
		t[1]=1;
		for(int i=1;i<=n;i++){
			int x=a[i]+d;
			if(x<a[i+1]){
				t[i+1]=i+1;
				pos[i]=i;
				now=i+1;
			}
			
			if(!t[i]){
				t[i]=t[i-1];
			}
			while(now<=n&&a[now]<=x){
				now++;
			}
			pos[i]=now-1;
		}
		for(int i=1;i<=n;i++){
			s[i]=0;int sum=0;
			for(int j=i-1;j>=t[i];j--){
				if(pos[j]>=i){
					s[j]=1;
					v[j]=1;	
				}else{
//					if(pos[j]-j<2){
//						v[j]=v[pos[j]]+1;
//						if(s[pos[j]]){
//							sum++;
//							s[j]=1;
//						}
//					}else if(pos[j]-j==2){
//						v[j]=v[pos[j]]+1;
//						if(v[pos[j]]==v[pos[j]-1]){
//							s[j]=1;
//							sum++;
//						}
//					}else{
//						v[j]=v[pos[j]]+1;
//						
//						if(v[pos[j]]==v[pos[j]-1]){
//							if(v[pos[j]]!=v[pos[j]-2]){s[j]=s[pos[j]];
//								s[j]=1;
//								sum++;
//							}
//						}
//					}
					int tmp=0;
					for(int k=pos[j];k>=max(j+1,pos[j]-3);k--){
						if(v[k]!=v[k+1]&&k!=pos[j])break;
						tmp+=s[k];
					}
					
					v[j]=v[pos[j]]+1;
					if(tmp==2){
						sum++;
						s[j]=2;
					}else{
						s[j]=1;
					}
				}
//				cout<<sum<<' ';
			}
			dp[i]=dp[i-1]+sum;
//			cout<<dp[i]<<' ';
//			cout<<'\n';
		}
//		cout<<"\n"; 
		cout<<dp[n]<<'\n';
	} 
	return 0;
}
