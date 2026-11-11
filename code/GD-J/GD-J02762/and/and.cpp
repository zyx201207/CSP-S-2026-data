
#include<bits/stdc++.h> 
using namespace std;
int n,m,a[1000005],b[1000005][2]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int xx=0;
	for(int i=n;i>=1;i--){
		int flag=1;
		for(int i=j;j<=xx;j++){
			if(a[i]==b[j][0]){
			b[j][1]++;flag=0;break;
		}
		}
		if(flag){
			xx++;
			b[xx][0]=a[i];
			b[xx][1]++;
		}
		for(int i=j;j<=xx;j++){
			if(b[j][1]>=m){
			cout<<b[j][0];return 0;
		}
		}
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
