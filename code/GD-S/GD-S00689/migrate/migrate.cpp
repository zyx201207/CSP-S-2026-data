#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long s[10000006];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int x=1;x<=n;x++){
			cin>>s[i];
		}
	
	for(int j=1;j<=n;j++)	
	int l=j,r=j+1;.
	if((s[r]-s[l]+2)/d>2){
		r--;
	}else{
		r++;
	}
	else if((s[r]-s[l]+2)/d==2)	{
		cout<<n/2;
	}
		
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
