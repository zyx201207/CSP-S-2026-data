#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[20000],d=1,su[20000]={0},f=1,t=0,o=0;
	cin>>n;
	char c[20000];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		if(c[i]!=c[i-1]&&i>0){
			d=0;
		}
		if(su[c[i]]==0){
			o++;
		}
		su[c[i]]+=a[i];
	}
	for(int i=97;i<=134;i++){
		for(int j=0;j<n;j++){
			if(su[c[j]]!=su[c[j-1]]){
				f=0;
				break;
			}
			t+=su[c[j]];
		}
	}
	if(n==1||d==1){
		cout<<"0";
	}else if(f==1){
		cout<<t/o;
	}
	return 0;
} 
