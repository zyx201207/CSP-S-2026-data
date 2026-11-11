#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a[20000],n,m,sum1[20000],f[20000]={0},s[20000]={0},d=0,p[20000]={0}; //a ÅÅÁÐ  s ¿¨ÅÆ 
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum1[a[i]]++;
	}
	for(int i=0;i<n;i++){
		d=0;
		int v;
		for(int j=n-1;f[a[j]]==0&&a[j]!=a[i];j--,d++){
			f[a[j]]=j;
			s[d]=a[j];
			p[d]=1;
			v=j-1;
//			cout<<a[j]<<" "<<a[i]<<" ";
		}
		if(a[v]!=a[i]&&f[a[v]]!=0){
			for(int x=0;x<f[a[v]]-v;x++){
				p[x]=0;
//				cout<<x<<" "<<p[x]<<" "<<a[f[a[v]]-v]<<endl;
			}
		}
		for(int x=0;x<d;x++){
			sum1[s[x]]+=p[x];
//			cout<<sum1[s[x]]<<" ";
			f[s[x]]=0;
		}
//		cout<<endl;
	}
	sum1[a[n-1]]=n;
	for(int i=1;i<=m;i++){
		cout<<sum1[i]<<endl;
	}
	return 0;
} 
