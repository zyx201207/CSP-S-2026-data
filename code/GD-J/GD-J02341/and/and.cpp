#include <bits/stdc++.h>
using namespace std;
int ma=0;
int main() {
	long long n,m,a[2000001];
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int m=a[i],s=a[j],a1[100001],a2[100001];
			int ans=1,cnt=1;
			while(m>=1){
				if(m==1){
					a1[ans]=m;
					m=0;
				}
				else if(m&2==1){
					a1[ans]=1;
					m=(m-1)/2;
				}
				else{
					a1[ans]=0;
					m=m/2;
				}
				ans++;
			}
			while(s>=1){
				if(s==1){
					a1[cnt]=s;
					s=0;
				}
				else if(s&2==1){
					a1[cnt]=1;
					s=(s-1)/2;
				}
				else{
					a1[cnt]=0;
					s=s/cnt;
				}
				cnt++;
			}
			cnt=min(cnt,ans);
			for(int k=1;k<=cnt;k++){
				if(a1[i]==a2[i])a1[i]=1;
				else a1[i]=0;
			}
			int ac=0;
			for(int k=1;k<=cnt;k++){
				ac+=pow(2,k-1)*a1[cnt-1+k];
			}
			ma=max(ac,ma);
		}
	}
	cout<<ma;
	return 0;
}
