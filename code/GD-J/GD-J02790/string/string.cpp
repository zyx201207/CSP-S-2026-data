#include <bits/stdc++.h>
using namespace std;
long long k=0,temp,s=0,n,a[10005];
string temp2,c[10005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>temp>>temp2;
		for(int j=1;j<=temp;j++){
			k++;
			c[k]=temp2;
		}
	}
	//for(int i=1;i<=k;i++)cout<<c[i]<<endl;
	if(k%2==0){
		for(int i=1;i<=k/2;i++){
			if(c[i]!=c[k-i+1])s++;
		}
	}
	else{
		for(int i=1;i<=k/2;i++){
			if(c[i]!=c[k-i+1])s++;
		}
	}
	cout<<s;
	cout<<endl;
	//for(int i=1;i<=k;i++)cout<<c[i]<<endl;
	return 0;
}

