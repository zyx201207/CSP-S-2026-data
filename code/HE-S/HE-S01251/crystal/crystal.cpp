#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    long long n,m,sum=0;
	long long a[100001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	long long b[100001];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			b[j]=a[j];
		}
		long long w=b[i];
		long long s=m;
		long long q=0;
		for(int j=i-1;j>1;j--){
		     if(b[j]==w){
				q+=1;
			}else{
				while(b[j]<w&&s>=1){
					b[j]+=1;
					s-=1;
				}
			}
			for(int k=1;k<i;k++){
				if(b[k]==w){
					q+=1;
				}
			}	 
    	}
		if(q>sum){
			sum=q;
			}
	}
	cout<<sum;
	return 0;
}
