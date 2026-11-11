#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
bool f[M];
int t[M];
int s[M];
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++){
			if(!f[a[j]]){
				f[a[j]]=true;
				t[a[j]]=j;	
			}else{
				for(int k=1;k<=m;k++){
					if(f[k]&&t[k]>=t[a[j]]&&t[k]<=j){
						f[k]=false;
						t[k]=0;
					}
				}
				f[a[j]]=true;
				t[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(f[j]){
			   s[j]++;
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
