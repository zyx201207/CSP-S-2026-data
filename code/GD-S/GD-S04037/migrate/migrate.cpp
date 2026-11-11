#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c1,t,n;
long long d,a[N],m,cnt=0;
int b[N],c[N];
bool f[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c1>>t;
	while(t--){
		cnt=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		
		for(int k=1;k<n;k++){
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(f,false,sizeof(f));
			int j;
		for(int i=k;i<=n;i++){
			j=i;
			if(f[i]) continue;
			while(a[++j]-a[i]<=m&&j<=n){
				if(f[j]) continue;
				if(b[j]==0||b[i]+1<b[j]){
					b[j]=b[i]+1;
					c[j]=1; 
				}else if(b[i]+1==b[j]){
					c[j]++;
				}
				if(c[j]>2) f[j]=true;
			}

		}
		
		for(int i=1;i<=n;i++) if(c[i]==2) cnt++;
		}
		cout<<cnt<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
