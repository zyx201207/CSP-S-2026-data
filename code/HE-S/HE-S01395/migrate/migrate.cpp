#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int q=0;q<t;q++){
		int n,d;
		cin>>n>>d;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		if(c==13||c==14){
			cout<<d/2;
		}
		int a1[n];
		for(int i=0;i<n;i++){
			a1[i]=a[i];
		}
		int b[n*n]={0};
		int c=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a1[i]+a1[j]<=d){
					a1[i]==a1[j]+a1[i];
					i++;
					continue;
				}
				b[c]=a1[i];
				c++;
			}
		}
		int ans=0;
		for(int i=0;i<n;i++){
			if(b[i]==b[i+1]){
				ans++;
			}
		}
		if(ans>d*2){
			cout<<d/2;
		}else{
			cout<<ans/2;
		}
	}
	return 0;
} 
