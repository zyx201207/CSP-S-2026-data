#include<bits/stdc++.h>
using namespace std;

int n,d,a[500005],p[50][50][50];


int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--){
		int ans=0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		
		for(int i=0;i<n;i++){
			
			for(int j=i;j<n;j++){
				if(j-i==2*d-1)ans++;
			}
		}
		
		cout<<ans<<endl;
	}
} 
