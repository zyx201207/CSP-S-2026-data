#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],maxx=-1,maxx1=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
	}else if(m==n-1){
		int b[200005];
		for(int i=0;i<n;i++){
			b[i]=0;
			for(int j=0;j<n;j++){
				if(j==i) continue;
				else b[i]&=a[j];
			}
			int maxx1=(maxx1,b[i]);
		}	
	}
	return 0;
}
