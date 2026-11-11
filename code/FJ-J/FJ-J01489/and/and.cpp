#include<bits/stdc++.h>
using namespace std;
long long ans,m,n,bns;
int s[200001],cns;
void abb(int m,int a){
	if(m==0)return;
	ans=0;
	if(cns==0){
		cns=1;
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				if(s[i] & s[j]>ans)ans=s[i] & s[j];
			}
		}
	}else{
	for(int i=1;i<=n;i++){
	if(s[i] & a>ans)ans=s[i] & a;
		
	}
	}
	abb(m-1,ans);
}
	
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	
	
	abb(m,s[1]);
	
	cout<<ans;
	
	
	
	
	
	
	
	
	
	return 0;
}
