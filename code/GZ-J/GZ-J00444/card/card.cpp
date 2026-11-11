//GZ-J00444 π®”Ó≥ø 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,cnt=0,m,temp1=0,temp2=0,cnt1=0,cnt2=0;
	cin>>n>>m;
	int a[n+50],b[n+50];
	if(m==1){
		cout<<n;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			temp1=0;
			temp2=0;
			for(int j=i;j<=n;j++){
				if(a[j]==1&&temp1==0){
					cnt1++;
					temp1=1;
				}
				else if(a[j]==2&&temp2==0){
					cnt2++;
					temp2=1;
				}
			}
		}
		if(cnt1)cout<<cnt1<<" ";
		if(cnt2)cout<<cnt2<<" ";
	}
	else for(int i=1;i<=n;i++)cout<<1<<" ";
	return 0;
}
