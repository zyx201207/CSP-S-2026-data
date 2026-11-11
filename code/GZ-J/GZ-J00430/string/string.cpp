//GZ-J00430 贵阳市第一实验中学 晏锦桐
#include<bits/stdc++.h>
using namespace std;
const int M=2e5+10;
int n,ti[M];
char tc[M];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ti[i]>>tc[i];
	}
	for(int i=1;i<=n/2;i++){
		int t=abs(ti[i]-ti[n-i+1]);
		if(tc[i]==tc[n-i+1]){
			if(t!=0&&(n-i+1)-i!=1){
				ans+=t;
				ti[n-i]-=t;
			}
		}else{
			ans+=max(ti[i],ti[n-i+1]);
		}
		
	}
	cout<<ans;
	return 0;
} 
