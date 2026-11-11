#include<bits/stdc++.h>
using namespace std;
long long b[3000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<long long>a;
	memset(b,0,sizeof(b));
	long long h[n];
	for(int i=0;i<n;i++){
		cin>>h[i];
	}
	for(int k=0;k<n;k++){
		for(int i=k;i<n;i++){
			for(int j=0;j<a.size();j++){
				if(a[j]==h[i]){
					for(int k=j;k<n;k++){
						a[k]=0;
					}
				}
			}
			a.push_back(h[i]);
		}
		for(int i=0;i<a.size();i++){
			b[a[i]]++;
		}
		for(int k=0;k<n;k++){
						a[2*k]=0;
					}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
