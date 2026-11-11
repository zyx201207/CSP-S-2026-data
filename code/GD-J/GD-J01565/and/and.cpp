#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,s[200005][31];
bool t[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int x;
	for(int i=1;i<=n;i++){
		x=a[i];
		for(int j=29;j>=0;j--){
			if(x%2==1){
				s[i][j]=1;
			}
			x/=2;
			if(x==0){
				break;
			}
			
		}
	}
	int b;
	for(int i=0;i<30;i++){
		for(int j=1;j<=n;j++){
			if(!t[j] and s[j][i]==1){
				b++;
			}
		}
		if(b>=m){
			for(int j=1;j<=n;j++){
				if(!t[j] and s[j][i]==0){
					t[j]=true;
				}
			}
		}
		b=0;
	}
	bool tt=1;
	for(int i=1;i<=n;i++){
		if(!t[i]){
			if(tt==1){
				ans=a[i];
				tt=0;
			}
			else{
				ans=(ans&a[i]);
			}
		}
	}
	cout<<ans;
	return 0;
} 
