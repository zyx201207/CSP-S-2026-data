#include<bits/stdc++.h>
using namespace std;
int n;
int a;
string c;
string s="";
long long ans=0;
long long cnt,cnt1=0;
int main(){
	freopen("string.in","r",strin)
	freopen("string.out","w",strout)
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>c;
		cnt+=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	while(cnt1<=cnt){
	
		
		int x=s[cnt-1],y=s[cnt1];
		if(x!=y){
			ans++;
		}
		cnt--;
		cnt1++;
	}
	cout<<ans;
	return 0;
}
