#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],ans[M],p[N];
vector<int>v[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				v[i].push_back(j);
				cout<<i<<' '<<j<<endl;
				break;
			}
		}
	}
	for(int i=n;i>=1;i--){
		if(i==n){
			ans[a[i]]++;
			continue;
		}
		for(int c:v[i]){
			for(int k=i;k<c;k++)p[k]=1;
		}
		for(int j=n;j>=i&&(!p[j]);j--)ans[a[j]]++;
	}
	for(int i=1;i<=n;i++)cout<<p[i]<<' ';
	return 0;
} 
