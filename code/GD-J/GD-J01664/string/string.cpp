#include<bits/stdc++.h>
using namespace std;
int n;//Trick||Treat!
string a[1000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int z=1;
	bool flag=1;
	int u,i;
	if(n==2){
		for(int i=1;i<=n;i++){
			int x,q=0;
			string b;
			cin>>x;
			cin>>b;
			if(q>=1){
				if(a[z]!=b){
				flag=0;	
			}
		}
			if (i==1){
				u==x;
			}else if(i==2){
				i==x;
			}
			for(int j=1;j<=x;j++){
				
				a[z]=b;
				z++;
			}
			q++;
		
		
		}
	}else{
	
		for(int i=1;i<=n;i++){
			int x,q=0;
			string b;
			cin>>x;
			cin>>b;
			if(q>=1){
				if(a[z]!=b){
				flag=0;	
			}
			}
			
			for(int j=1;j<=x;j++){
				
				a[z]=b;
				z++;
			}
			q++;
			
			
		}
	}	
	if(n==1){
		cout<<0;
	}
	else if(n==2){
		if(u>i){
			cout<<u;
		}else{
			cout<<i;
		}
	}
	else if(flag=1){
		cout<<0;
	}
	
	return 0;
}
