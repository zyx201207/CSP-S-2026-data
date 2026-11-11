#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[100009],s[1000],u;
int main(){
	freopen("magrate.in","r",stdin);
	freopen("magrate.out","w",stdout);
	cin>>c>>t;
	for(int p=1;p<=t;p++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n-4;i++){
			for(int j=i+3;j<=n;j++){
				if(x[j]-x[i]<=d*2){
					s[p]++;
					u++;
				}
			} 
		}
	}
	cout<<0<<endl;
	for(int i=1;i<=u;i++){
		cout<<s[i]<<endl;
	}
} 
