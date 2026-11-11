#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a=0,ans=-1;
	cin>>a;
	long long a1[a+10];
    string k,t;
    long long jian=0;
	char c;
	long long o=0;
	for(int i=0;i<a;i++){
		cin>>a1[i]>>c;
		
	   for(int j=0;j<a1[i];j++){
	   	k[jian+j]=c;
	   }
	   jian+=a1[i];
	}
	for(int i=jian;i>=0;i--){
		t[o]=k[i];
		o++;
	}
	for(int i=0;i<jian;i++){
		if(k[i]!=t[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
