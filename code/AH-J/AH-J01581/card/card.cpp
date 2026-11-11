#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[100005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long sum[100005]={0};
	for(int i=0;i<n;i++){
		long long b[100005]={0};
		for(int j=i+1;j<n;i++){
			for(int g=0;g<j;g++){
				if(b[g]==a[j]){
					for(int d=g;d<j;j++)
						b[d]=0;
				}
			}
			b[j]=a[j];
		}
		for(int j=1;j<=m;j++){
			sum[b[j]]++;
		}
	}
	cout<<sum;
	return 0;
}
