#include<bits/stdc++.h>
using namespace std;
int main(){
     freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
    cin>>n;
    long long int a[n+1]={},mun=0;
	char s[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=1;i<=n/2;i++){
		if(s[i]!=s[n-1+i]){	
		      
			mun+=max(a[i],a[n-i+1]);
		}
		
	 }
	cout<<mun;
	return 0;
}




