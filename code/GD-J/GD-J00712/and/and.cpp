#include<bits/stdc++.h>
using namespace std;
long long a[200005];
string b[200005]={""};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	if(m==2){
		for(int i=0;i<n;i++){
			cin>>a[i];
			string s="";
			while(a[i]>0){
				s+=(a[i]%2+'0');
				a[i]/=2;
			}
			for(int j=s.size()-1;j>=0;j--)b[i]+=s[j];
		}
		long long maxn=0;
		for(int i=0;i<n-1;i++){
			long long maxnn=0; 
			for(int j=i+1;j<n;j++){
				long long sum=0;
				long long minl=min(b[i].size(),b[j].size());
				long long x=b[i].size()-1,y=b[j].size()-1;
				long long q=0;
				while(minl>0){
					if(b[i][x]==b[j][y] and b[i][x]=='1'){ 
						sum+=(1ll*pow(2,q));
					}
					q++;
					x--;y--;
					minl--;
				}
				maxnn=max(sum,maxnn);	
			}
			maxn=max(maxn,maxnn);
		}
		cout<<maxn;
	}else{
		for(int i=0;i<n;i++)cin>>a[i];
		cout<<0;
	}
	return 0;
}
