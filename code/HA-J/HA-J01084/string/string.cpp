#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,ans;
	long long b[100000];
	string c;
	for(int i=0;i<=a;i++){
		cin>>b[i]>>c[i];
	}
	for(int i=1;i<=a;i++){
		if(i==c[i]+1-i){
			ans=ans;
		}else{
			ans++;
		}
		
	}
	cout<<ans<<endl
	;
	return 0;
}
