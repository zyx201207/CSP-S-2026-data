#include <bits/stdc++.h>
using namespace std;
int n,m;
long long b[500005],a[500005];
string p;
int check(int y)
{
	for(int i=1;i<=p.size();i++){
		if(p[i]==a[y])return i;
	}
	return 0;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int x=1;x<=m;x++){
		for(int i=1;i<=p.size();i++)p[i]=0;
		for(int i=x;i<=n;i++){
			if(check(i)!=0){
				for(int j=check(i)+1;j<=p.size();j++){
					p[j]=0;
				}
			}else{
			    p[i]=a[i];	
			}
		}
		for(int i=1;i<=p.size();i++){
			if(p[i]!=0)b[p[i]]+=1;
		}
	}for(int i=1;i<=500005;i++){
		if(b[i]!=0)cout<<b[i]<<" ";
	}
	return 0;
}
