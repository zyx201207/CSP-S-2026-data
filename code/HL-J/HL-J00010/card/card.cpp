#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	int k[100003]={0},s[100003]={0},n[100003]={0};
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>k[i];
		c=k[i];
		if(s[c]<1){
		    s[c]++;
		}
		else{
			n[c]=s[c]+1;
			for(int j=1;j<=10001;j++){
				n[j]+=s[j];
				s[j]=0;
			}
		}
	}
	n[c]=a;
	for(int i=1;i<=10001;i++){
		if(n[i]!=0){
			cout<<n[i]<<" ";
		}
	}
}
