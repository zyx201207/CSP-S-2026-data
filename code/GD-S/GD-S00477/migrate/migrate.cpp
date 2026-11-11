#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int a[100005];

bool b(int x,int y){
	int k,l;
	
	return k==l&&k!=0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int sum=0;
		memset(a,0,sizeof(a));
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(b(i,j)){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

