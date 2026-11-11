#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100];
int s[100];
int d[100];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int l=0;
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>a[i];
	} 
	while(n--){
		int k;
		cin>>k;
		for(int i=0;i<=k;i++){
			cin>>b[l];
			cin>>s[l];
			l++;
		}
	} 
	while(q--){
		int r=0;
		int x;
		int y;
		cin>>x>>y;
		for(int j=0;j<l;j++){
		for(int i=y;y>=x;y--){
			if(b[j]==i){
			r=r+s[j];	
			}
		}
	}
	cout<<r+a[x]+a[y];
}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
