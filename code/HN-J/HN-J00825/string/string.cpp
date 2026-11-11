#include<bits/stdc++.h>
using namespace std;
long long t[1000050],n,len,lenx,ans,b[100],b2[100];
char a[1000050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i];
		len+=t[i]; 
		cin>>a[i];
		b2[a[i]-'a']+=t[i];
	}
	for(int i=1;i<=n;i++){
		if(lenx<=len/2){
			if(lenx+t[i]<=len/2){
				b[a[i]-'a']+=2*t[i];
			
			}
			else{
				b[a[i]-'a']+=2*(t[i]-(lenx+t[i]-len/2));
			}
		}
		lenx+=t[i];
	}
	
	for(int i=0;i<26;i++){
		if(b[i]>b2[i]){
			ans+=b[i]-b2[i];
		}
	}
	cout<<ans;
	return 0;
}

