#include<bits/stdc++.h>
using namespace std;
int a[50050],qzh[50050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0,a1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a1=a[1];
	a[1]+=m;
	for(int i=1;i<=n;i++){
		qzh[i]=a[i]+qzh[i-1];
	}
	for(int i=1;i<=n;i++){
		if(qzh[i]%i==0){
			bool flag=1;
			int ave=qzh[i]/i;
			for(int j=1;j<=i;j++){
				if(((j==1)&&(ave<a1))){
					flag=0;
					break;
				}
				else if((j!=1)&&(ave<a[j])){
					flag=0;
					break;
				} 
			}
			if(flag){
				ans=max(ans,i);
			}
		}
	}
	cout<<ans;
	return 0;
}
