#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[200001],b[200001],c[200001];
	cin>>n>>m;
	bool yes=true;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		b[i]=0;
		if(a[i]<a[i-1]){
			yes=false;
		}
	}
	if(yes==true){
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if(a[j]==a[j-1]){
					j++;
				}else{
					b[i]++;
				}
			}
		}
		for(long long i=1;i<=n;i++){
			cout<<b[i];
		}
	}else{
		for(long long i=1;i<=n;i++){
			int c1=0;
			for(int j=i;j<=n;j++){
				bool tong=false;
				int abc=0;
				int k=1;
				for(;k<=c1;k++){
					if(a[k]==a[j]){
						tong=true;
						abc=k;
						break;
					}
				}
				if(tong==true){
					c1=abc;
					c[c1]=a[j];
				}else{
					c1++;
					c[c1]=a[j];
				}
			}
			for(int i=1;i<=c1;i++){
				b[c[i]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
	}
	
	return 0;
}

