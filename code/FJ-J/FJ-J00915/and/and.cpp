#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],b[N];
string s[N];
int jz[35];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(a[i]){
			if(a[i]%2==1){
			 s[i]+='1';
			}else{
				s[i]+='0';
			}
			a[i]/=2;
		}
	}
	int max=-1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<s[i].size();j++){
			if(s[i][j]=='1'){
				jz[j+1]++;
			}
		}
	}
	int num=0;
	long long ans=0;
	for(int i=35;i>=1;i--){
		
		if(jz[i]>=m){
			for(int j=1;j<=n;j++){
				if(s[j][i-1]!='1'&&b[j]!=1) b[j]=1,num++;
			}
			
			if((n-num)>=m){
				int q=i,x=1;
				while(q--){
					x*=2;
				}
				x/=2;
				ans+=x;
			}
		}
	}
	cout<<ans;
	return 0;
}
