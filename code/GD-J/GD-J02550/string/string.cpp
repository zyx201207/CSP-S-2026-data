#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	const int N=1e6;
	int n,m,ans=0;
	char a[N],str;
	bool flag=true;
	cin>>n;
	while(n--){
		cin>>m;
		cin>>str;
		while(m--) a[ans++]=str;
	}
	for(int i=1;i<=ans/2;i++){
		if(a[i]!=a[ans-i]) flag=false; break;
	}
	if(flag){
		cout<<0;
		return 0;
	}else{
		cout<<2;
		return 0;
	}
	
	return 0;
} 
