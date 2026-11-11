#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	long long n,m,anss[m]={0};
	cin>>n>>m;
	long long a[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<n;j++){
			if(a[j]==a[i]){
				for(int h=j+1;h<n;h++){
					a[h]=0;
				}
			}
		}
	}for(int i=0;i<n;i++){
		if(a[i]!=0){
			anss[a[i]]++;
		}
	}for(int i=m-1;i>=0;i--){
		cout<<anss[i]<<" ";
	}
	return 0;
}
