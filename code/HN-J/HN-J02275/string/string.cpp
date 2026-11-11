#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>>n;
	int a[100000];
	string arr[100000];
	
	int d;
	cin>>d;
	string p;
	cin>>p;
	int y=0;
	for(int i=1;i<n;i++){
		cin>>a[i]>>arr[i];
		if(arr[i]!=p){
			y++;
		}
	}
	if(y==0){
		cout<<y;
	}else{
		string zui;
	
	for(int i=0;i<d;i++){	
		zui+=p;
	}
		
	for(int i=1;i<=n;i++){	
		for(int j=0;j<a[i];j++){
			zui+=arr[i];
		}		
	}
	
	
		
		
		string X;
		string Y;
		for(int i=0;i<zui.size()/2;i++){
			X+=zui[i];
		}

		for(int j=zui.size()-1;j>=(zui.size()+1)/2;j--){
			Y+=zui[j];
		}	
		
		int E=X.size();
		int ans=0;
		for(int g=0;g<E;g++){
			if(X[g]!=Y[g]){
				ans++;
			}
		}
		cout<<ans;		

	





	}
	
	
	
	
	
	
	return 0;	
}
