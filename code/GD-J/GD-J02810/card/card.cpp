#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	long long a[n],ans[m]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		bool b[m]={false};
		int t[n]={0};
		for(int j=i;j<n;j++){
			if(!b[a[j]-1]){
				t[j] = a[j];
				b[a[j]-1]=true;
			}
			else{
				bool p=false;
				for(int k=0;k<n;k++){
					if(p) t[k]=0;
					if(t[k]==a[j]) p=true;
				}
			}
		}
		for(int k=0;k<n;k++){
			if(t[k]) ans[t[k]-1]++;
		}
	}
	ans[a[n-1]-1]=n;
	for(int i=0;i<m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
