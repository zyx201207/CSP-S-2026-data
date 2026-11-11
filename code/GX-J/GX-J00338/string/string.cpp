#include<bits/stdc++.h>
using namespace std;
int a[1000000]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=1;
	cin>>n;
	while(n--){
		int g;
		char s;
		cin>>g>>s;
		for(int i=cnt ;i<=cnt+g;i++){
			a[i]=s;
		}
		cnt+=g;
	}
	int ans=0;
	if(cnt/2==0){
		int z=cnt/2;
		for(int i=1;i<z;i++){
			if(a[z-i]!=a[z+i]) ans++;
		}
	}
	else{
		int l=cnt/2,r=cnt/2+1;
		for(int i=0;i<l;i++){
			if(a[l-i]!=a[r+i]) ans++;
		}
	}
	cout<<ans;
}
