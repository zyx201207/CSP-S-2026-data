#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f

string s="";
int a[10000010];
int b[10000100];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
	string s="";
		for(int j=i;j<n;j++){
			char p=char(a[j]+48);
		   if(s.find(p)>n) {
		   	s+=char(a[j]+48);
		   }
		   else{
		   	int q=s.find(p);
		   	s.erase(q+1);
		   }
		}
	for(int j=0;j<s.size();j++){
		for(int k=1;k<=m;k++){
			char r=char(k+48);
			if(s[j]==r) b[k]++;
		}
	}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
