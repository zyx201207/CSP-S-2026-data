#include<bits/stdc++.h>
using namespace std;
bool c[200010][50];
int len[200010];
bool f[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,Maxlen=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		while(x){
			c[i][++len[i]]=x%2;
			x/=2;
		}
		Maxlen=max(Maxlen,len[i]);
	}
	/*for(int i=1;i<=n;i++){
		for(int j=len[i];j>=1;j--)
			cout<<c[i][j];
		cout<<endl; 
	}*/
	long long Max=0;
	for(int i=1;i<=Maxlen;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			if(c[j][i])
				ans++;
		}
		if(ans>=m)
			Max=i;
	}
	for(int i=1;i<=n;i++)
		if(c[i][Max])
			f[i]=1;
	long long sum=pow(2,Max-1);
	for(int j=Max-1;j>=1;j--){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(c[i][j]&&f[i])
				ans++;
		}
		//cout<<ans<<" "<<m<<endl;
		if(ans>=m){
			for(int i=1;i<=n;i++){
				if(!c[i][j])
					f[i]=0;
			}
			sum+=pow(2,j-1);
		}
	}
	cout<<sum;
	return 0; 
} 
