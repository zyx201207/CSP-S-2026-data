#include<bits/stdc++.h>
using namespace std;
int l;
int a[10000000],sum=0;
string s,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	 cin>>l;
	 for(int i=0;i<l;i++){
		cin>>a[i]>>s[i];
		for(int j=0;j<a[i];j++){
			b+=s[i];
		}
	}
	if(b.size()%2==0){
		for(int j=b.size()/2;j>0;j--){
			if(b[b.size()-j]!=b[j-1]){
				sum+=1;
			}
		}
	}else{
		for(int j=(b.size()+1)/2;j>=0;j--){
			if(b[b.size()-j]!=b[j-1]){
				sum+=1;
			}
		}
	}	
	cout<<sum;
	return 0;
}
