#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long n,ans=0,a,rev=0;
	char b;
	cin>>n;
	long s[n*2];
	for(int i=0;i<n;i++){
		cin>>a>>b; 
		ans+=a;
		s[i*2]=a;
		s[i*2+1]=b;
	}
	string ls[ans]={};
	int al=0;
	for(int j=0;j<n;j++){
		for(int m=0;m<s[j*2];m++){
			ls[al]=s[j*2+1];
			al+=1;
		}
	}
    for(int x=0;x<ans;x++){
    	if(ls[x]!=ls[ans-x-1]){
    		rev+=1;
    		ls[ans-x-1]=ls[x];
		}
	}
	cout<<rev;
}
