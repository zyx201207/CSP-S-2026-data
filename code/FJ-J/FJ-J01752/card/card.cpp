#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long sum[300005];
long long p[500010];
long long pai=0;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		pai=0;
		for(int j=i; j<=n; j++) {
			long long temp=0;
			for(int k=0;k<=pai;k++){
				if(p[k]==a[j]){
					temp=k;
					break;
				}
			}
			if(temp!=0){
				pai=temp;
			}else{
				pai++;
				p[pai]=a[j];
			}
		}
		for(int j=1;j<=pai;j++){
			sum[p[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}





	return 0;
}
