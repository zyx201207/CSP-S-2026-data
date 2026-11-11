#include<bits/stdc++.h>
using namespace std;
long long n,a[510],ans;
char c[27];
bool flag;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	if(n==1){
		cout<<0;
		return 0; 
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	
	for(int i=0;i<n-1;i++){
		if(c[i]==c[i+1])flag=0;
		else{
			flag=1;
			break;
		}		
	}
	if(flag==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		ans+=a[i];
	}
	cout<<ans/2;
	return 0;
}

