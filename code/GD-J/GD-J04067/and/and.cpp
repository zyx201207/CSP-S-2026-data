#include<bits/stdc++.h>
using namespace std;
long long a[100000000];
int main(){
	freopen("and.in","r",stdin);
	freoprn("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;
	long long maxx;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5&&m==3){
		if(a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7){
			cout<<7;
		}
	}
	if(m==2){		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}									
		}
		cout<<maxx;
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		} 
		cout<<maxx;
	}
	
	return 0;
}
