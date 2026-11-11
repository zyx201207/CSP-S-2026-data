//GZ-S00345 贵阳市南明区新世界学校 文希昊 
#include<bits/stdc++.h> 
using namespace std;

long long n,m,a[600000]={},b[600000]={},maxn=-2e9;

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=1;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(a[i]!=a[i+1]){
			int sum=m;
			for(int j=i-1;j>=0;j--){
				if(a[i]-a[j]<=sum){
					sum=sum-(a[i]-a[j]);
					b[i]++;
				}else{
					break;
				}
				
			}
		}
	}
	for(int i=0;i<n;i++){
		if(b[i]>=maxn)maxn=b[i];
	}
	cout<<maxn;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
