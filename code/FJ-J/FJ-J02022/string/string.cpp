#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010],b[100010],k=0,ans=0;
int s[10000010];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	char cf;
    	cin>>cf;
    	b[i]=cf-96;
    	int max=k+a[i]+1;
    	for(k=k+1;k<max;k++){
    		s[k]=b[i];
		}
		k--;
	}
	for(int i=1;i<=k/2;i++){
		if(s[i]!=s[k-i+1]) ans++;
	}
	cout<<ans;
	return 0;
} 
