#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){

		sort(a+1,a+n+1);
		int R=n;
		int cnt=0;
		while(R){
			int i=R;
			int cz=m;
			int sam=0;
			while(cz>0&&i!=0){
	
				cz-=(a[R]-a[i]);
				sam++;
				i--;
			}
			if(i==0&&cz>=0){
				cout<<R;
				exit(0);
			}else if(i==0){
				cout<<R-1;
				exit(0);
			}
			cnt=max(sam,cnt);
			R--;
			
		}
		cout<<cnt;		
	}else {

//4 2
//7 8 9 10
		int t=a[2]-a[1];
		int i;
		int x=0;
		for(i=1;x<=m&&i<n;i++)x+=i*t;
		if(x<=m){
			cout<<n;
			exit(0);
		}else{
			cout<<i-1;
			exit(0);
		}
	}

} 
