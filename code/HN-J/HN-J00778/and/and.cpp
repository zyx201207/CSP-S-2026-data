#include<bits/stdc++.h> 

using namespace std;
int ans[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
int m,n,a,b,c,d;
cin>>m>>n;
for(int i=1;i<=n;i++){
	cin>>ans[i];
	for(int j=1;j<=n;j++){
		if(ans[i],ans[j]>b){
			b=and(ans[i],ans[j]);
		}
	}
}
	cout<<b;
		
	return 0;
}
