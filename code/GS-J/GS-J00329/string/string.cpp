#include<bits/stdc++.h>
using namespace std;
int s[10100];
int main(){
	int n;
	cin>>n;
	int a[10010];
	int b=0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for(int i=0;i<n;i++){
		cin>>s[i];
		while(s[i]>0){
			s[i]=s[i]%10;
			a[i]+=s[i];
			s[i]=s[i]/10;
		}
	}
	if(s[i]=a[i]){
		cout<<b;
	}else{
		cout<<b+1;
	}
	return 0;
}
