#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,finaly;
int a[N],j[N],MAX;
string BIN[N],final;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){//DEC -> BIN
		cin>>a[i];MAX=max(MAX,a[i]);
		string s;
		while(a[i]>0){
			s[j[i]]=(a[i]%2+'0');
			a[i]/=2,j[i]++;
		}
		for(int k=j[i]-1;k>=0;k--)BIN[i]+=s[k];
	}
	if(m==1)cout<<MAX;
	MAX=0;
	for(int i=1;i<n;i++){
		for(int k=i+1;k<=n;k++){
			string final;
			int len=max(j[i],j[k]),y=0,f=0;
			y++;
			for(int z=0;z<len;z++,f++){
				if(BIN[i][z]==1&&BIN[k][z]==1)final[y]='1';
				else final[y]='0';
			}
			for(int z=f-1;z>=0;z++){
				int p=pow(2,f-1-z);
				finaly+=final[z]*p;
			}
			MAX=max(MAX,finaly);
			finaly=0;
		}
	}
	cout<<MAX;
	
	return 0;
} 

