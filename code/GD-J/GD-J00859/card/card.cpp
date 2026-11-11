#include<bits/stdc++.h>
using namespace std;
long long a[1000100],b[1000100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	string p="";
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int flag=1;
			for(int k=0;k<p.length();k++){
				if(flag==0){
					p[k]=-1;
				}
				if(p[k]==a[j]){
					flag=0;
				}
			}
			p+=a[j];
		}
		for(int j=1;j<=m;j++){
			for(int k=0;k<=p.length();k++){
				if(j==p[k]){
					b[j]++;
					break;
				}
			}
		}
		for(int j=0;j<p.length();j++){
			p[j]=-1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
}
