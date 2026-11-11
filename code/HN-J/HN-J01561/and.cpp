#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
long long maxx=0;
long long a[maxn];
int n,m;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
	}
	cout<<maxx;
	return 0;
}
