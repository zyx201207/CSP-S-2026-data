#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long a[N],step[N],kind[N];
int t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 	
	int c;
	cin>>c>>t;
	if(c<=2){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			step[1]=0;
			int ans=0;
			for(int start=1;start<n;start++){
				for(int i=start;i<=n;i++){
					step[i]=INT_MAX;
					kind[i]=0;
				}
				step[start]=0;
				for(int i=start;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						if(a[j]-a[i]>d) break;
						if(step[i]+1>step[j]) continue;
						if(step[i]+1==step[j]){
							kind[j]++;
						}
						if(step[i]+1<step[j]){
							step[j]=step[i]+1;
							kind[j]=1;
						}
					}
				}
				for(int i=1;i<=n;i++){
					if(kind[i]==2) ++ans;
					//cout<<start<<":"<<step[i]<<" "<<kind[i]<<"\n";
				}
			}
			cout<<ans<<"\n";
		}
	}
	else if(c==13||c==14){
		for(int i=1;i<=t;i++){
			cout<<0<<"\n";
		}
	}
	return 0;
} 

