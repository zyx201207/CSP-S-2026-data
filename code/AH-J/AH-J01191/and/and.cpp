#include<bits/stdc++.h>
using namespace std;
int a[200005];
string s[200005];
string s1;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,ans=0,maxv=0,maxshu=0;
	cin>>n>>m;
	if(m==2){
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxshu)maxshu=a[i];
		while(a[i]!=0){
			s[i]+=a[i]%2+'0';
			a[i]/=2;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=0;k<max(s[i].size(),s[j].size());k++){
					if(s[i][k]==s[j][k]&&s[i][k]=='1'){
						ans+=pow(2,max(s[i].size(),s[j].size())-k-1);
					
						if(ans>maxv)maxv=ans;
					}
				}
				ans=0;
			}
		}
		cout<<maxv;
	}
	else if(m==1){
		while(maxshu!=0){
			s1+=maxshu%2+'0';
			maxshu/=2;
		}
		cout<<s1;
		}
	else {
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		int ans=a[n-m+1];
		
		cout<<ans;
	}
		
	return 0; 
}
