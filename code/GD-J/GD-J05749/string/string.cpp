#include<bits/stdc++.h>
using namespace std;
int n; 
int ans;
int sum;
int a[10000001];
string s;
char c[100000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		 sum+=a[i];	
		 if(i>=a[i])
	}
	int l=sum/2;
	int r=sum/2;
	for(int i=1;i<=sum;i++){
		if(sum%2==0){
		if(a[l-i]!=a[r+i-1]) ans++;
		else ans=ans;
		}
		else{
			if(a[l-i]!=a[r+i]) ans++;
			else ans=ans;
		}
		
	}
	cout<<ans;
 return 0;
}
