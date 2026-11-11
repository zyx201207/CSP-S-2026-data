#include<bits/stdc++.h>
using namespace std;
long long c[200010];
int main(){
	feropen("and.in","r",stdin);
	feropen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,s=0,mj=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){		
		for(int j=i+1;j<=m;j++){
			mj=c[i]&c[j];			
		}
		s=max(s,mj);
	}
	cout<<s;
return 0;
}
