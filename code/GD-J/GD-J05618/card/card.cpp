#include<bits/stdc++.h>
using namespace std;
string s;	
string x[100000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],i,j,k,l=0;
	for(i=0;i<n;i++)cin>>a[i];
	for(k=1;k<=n;k++){
		s="";
		for(i=l;i<n;i++){
			int f=1,id=0;
			for(j=0;j<s.size();j++){
				if(a[i]==s[j]-'0'){
					id=j;
					f=0;
					break;
				}
			}
			if(f==0)s=s.substr(0,id);
			s+=a[i]+'0';	
		} 
		x[l]=s;
		l++;
	}
	int h[m]={0};
	for(i=1;i<=m;i++){
		for(j=0;j<=l;j++){
			for(k=0;k<x[j].size();k++){
				if(x[j][k]-'0'==i)h[i]++;
			}
		}
		cout<<h[i]<<' ';
	}
	return 0;
}
 
