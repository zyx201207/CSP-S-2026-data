#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long b[200005],cnt,ans;
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	if(cnt%2==1){
		long long sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			if(sum>cnt/2){
				a[i]-1;
			}
		}
		cnt/=2;
	}else{
	    cnt/=2;		
	}
	while(cnt!=0){
		long long sum=0;
		for(long long i=1;i<=n;i++){
			sum+=a[i];
			if(sum>cnt){
				long long x=cnt-(sum-a[i]),y=sum-cnt;
				if(y>x){
					a[i]-=x*2;
				}else if(y<x){
					a[i]-=y*2;
					long long I=i+1;
					while(a[i]!=0){
						if(a[i]>=a[I]){
							a[i]-=a[I];
							ans+=a[I];
							a[I]=0;
						}else{
							a[I]-=a[i];
							ans+=a[i];
							a[i]=0;
						}
					}
				}
			}else if(sum==cnt){
				long long x=a[i];
				long long y=a[i+1];
				if(c[i]==c[i+1]){
					if(x>y){
					    a[i]-=a[i+1];
					    a[i+1]=0;
				    }else if(x<y){
					    a[i+1]-=a[i];
					    a[i]=0;
				    }else{
				    	a[i+1]=0;
				    	a[i]=0;
					}
				}else if(x>y){
					ans+=a[i+1];
					a[i]-=a[i+1];
					a[i+1]=0;
				}else{
					ans+=a[i];
					a[i+1]-=a[i];
					a[i]=0;
				}
				break;
			}
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=a[i];
		}
	    cnt/=2;		
	}
	cout<<ans;
	return 0;
}
