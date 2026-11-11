#include<bits/stdc++.h>
using namespace std;
long long a[2000002],b[2000002];
long long zui[2000002][2000002];

long long n,m;

int main(){
	freopen("migrate.in","w",stdin);
	freopen("migrate.out","r",stdout);
	int c,t;
	cin>>c>>t;
	for(int q1=1;q1<=t;q1++){
		int n,m,num=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			int a1;
			cin>>a1;
			a[i]=a1;
		}
		for(int i=1;i<=n;i++){
			b[i]=a[i]-a[i-1];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(j-i%2==0){
					num++;
				}
			}
		}
		cout<<num;
	}

	return 0;
} 
