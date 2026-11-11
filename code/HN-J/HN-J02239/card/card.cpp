#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,i,j,k=0,x,p;
	cin>>n>>m;
	long long a[n],b[m]={0};
	vector<long long> v;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(j=0;j<n;j++){
		for(i=k;i<n;i++){
			long long l=v.size(),z=0;
			for(p=0;p<l;p++){
				if(v[p]!=a[i])z++;
			}
			if(z==l)v.push_back(a[i]);
			else{
				v.erase(v.begin(),v.end());
				v.push_back(a[i]);
			}
		}
		for(x=0;x<v.size();x++){
			b[v[x]-1]++;
		}
		v.erase(v.begin(),v.end());
		k++;
	}
	for(i=0;i<m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
