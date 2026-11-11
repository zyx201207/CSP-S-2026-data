#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m,b[18]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072},cnt=0,cnt2=0;
	string s;
	cin>>n>>m;
	long long a[n+12];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]-a[n-1]==a[n-1]+1){
		cout<<a[n-m];
	}else{
		if(a[n]-a[n-1]==1){
			for(int i=1;i<=n;i++){
				for(int j=0;j<18;j++){
					if(a[i]==b[j]-1){
							cnt++;			
					}
				}
			}
			cout<<cnt;
		}else{
			for(int i=1;i<=n;i++){
				cnt2=a[i];
				while(cnt2>0){
					s+=char(cnt2%=2);
					cnt/=2;
				}
				if(s[i]=='1'){
					cnt++;
				}
			}
			cout<<cnt;
		} 
	}
	return 0;
}
