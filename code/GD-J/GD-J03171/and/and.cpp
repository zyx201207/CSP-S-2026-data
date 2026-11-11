#include<bits/stdc++.h>
const int N=2*1e5+5;
using namespace std;
int mp[N][35];
int a[N];
int l=0; 
void change(int n){
	int x=a[n];
	int i=0; 
	while(x){
		i++;
		mp[n][i]=x%2;
		x/=2;
	}
	l=max(l,i);
	mp[n][0]=1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		change(i);
	}
	int ans=0;
	for(int i=l;i>=1;i--){
		int k=0;
		for(int j=1;j<=n;j++){
			if(mp[j][i]&&mp[j][0]==1){
				k++;
			}
		}
		if(k>=m){
			ans+=(1<<(i-1));
			for(int j=1;j<=n;j++){
				if(!(mp[j][i]&&mp[j][0]==1)){
					mp[j][0]=0;
				}
			}
		}else {
		}
	}
	cout<<ans;
	return 0;
}

