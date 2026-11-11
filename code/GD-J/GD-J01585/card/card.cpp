#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5,M=3e5+5;
int c[N];
int ans[M];
int n,m;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	} 
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			ans[c[i]]++;
			for(int j=i+1;j<=n;j++){
				if(c[j]==c[i])i=j-1;
			}
		}
		for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


