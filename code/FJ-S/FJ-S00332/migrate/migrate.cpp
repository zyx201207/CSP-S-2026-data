#include<bits/stdc++.h>
using namespace std;
#define awa cout
const int MAXN=2000010;
int x[MAXN],way[MAXN],away[MAXN];
int n,d,c,t;
int ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		
		
		
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int s=1;s<n;s++){
			way[s]=1;
			away[s]=0;
			
			int near;
			int last=s;
			for(int i=s+1;i<=n;i++){
				near=0x3fffffff;
				bool aaa=1;
				for(int j=last;j<i;j++){
					if(x[i]-x[j]>d){
						continue;
					}
					else if(aaa){
						near=away[j];
						way[i]=way[j];
						aaa=0;
						last=j;
						continue;
					}
					if(away[j]==near){
						way[i]+=way[j];
					}
					else if(away[j]<near){
						near=away[j];
						way[i]=way[j];
					}
				}
				away[i]++;
				if(way[i]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
















/*
#include<bits/stdc++.h>
using namespace std;
#define awa cout
const int MAXN=2000010;
int x[MAXN],way[MAXN],away[MAXN];
int n,d,c,t;
int ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--)
	
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>x[i];
	}
	way[1]=1;
	away[1]=0;
	int last=1;
	int near;
	for(int i=2;i<=n;i++){
		near=away[last];
		for(int j=last+1;j<i;j++){
			if(x[i]-x[j]>d){
				last=j+1;
				continue;
			}
			if(away[j]<near){
				near=away[j];
				way[i]=way[j];
			}
			else if(away[j]==near){
				way[i]+=way[j];
			}
		}
		if(way[i]>1){
			ans++;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
*/
