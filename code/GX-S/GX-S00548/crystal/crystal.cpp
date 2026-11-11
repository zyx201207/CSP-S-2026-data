#include<bits/stdc++.h>
using namespace std;
long long n,m;
int cry[500001];
long long cry1[500001];
long long min1[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);  
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>cry[i];
	}
	sort(cry,cry+n);
	if(n>1000){
		cry1[0]=cry[0];
		for(int i=1;i<n;i++){
			cry1[i]=cry1[i-1]+cry[i];
		}
		for(int i=0;i<n;i++){
			if(cry[i]*(i+1)-cry1[i]>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	for(int i=0;i<=n;i++)min1[i]=1e18;
	for(int i=0;i<n;i++){
		for(int id=0;id<n;id++){
			int sum=0;
			if(id+i>=n)break;
			for(int j=id;j<=id+i;j++)sum+=cry[j];                                              
			int f=cry[id+i]*(i+1)-sum;
			if(f<min1[i]){
				min1[i]=f;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(min1[i]>m){
			cout<<i;
			return 0;
		}
	}
	
	return 0;
}
