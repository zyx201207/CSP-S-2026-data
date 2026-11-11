#include<bits/stdc++.h>
using namespace std;
int const N=2e5+10;
long long a[N],p[N],s[N];
long long ans[N];
long long n,m;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			p[i]=0;s[i]=0;
		}
		int cnt=1;
		for(int j=i;j<=n;j++){
			int x=a[j];
			if(p[x]==0){
				p[x]=1;
				s[cnt]=x;
				cnt++;
			}else{
				while(true){
					if(s[cnt-1]==x){
						
					
						break;
					}
					s[cnt-1]=0;
						cnt--;
					
				}
				
				
			}
		}for(int j=1;j<=cnt;j++){
			ans[s[i]]++;
			
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	
	return 0;
} 
