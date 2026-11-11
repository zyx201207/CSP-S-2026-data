#include<bits/stdc++.h>
using namespace std;
int t(int a[],int q,int z,int d){
	int cnt=0;
	for(int i=q;i<=z){
		int now=a[i];
		while(1){
			i++;
			if(a[i]>now+d){
				cnt++;
				i--;
				break;
			}
		}
	}
	return cnt;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		unsigned long long n,d;
		cin>>n>>d;
		int a[n+3];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;i<=n;i++){
				ml=t(a,i,j,d);
			}
		}
	}
	return 0;
} 
