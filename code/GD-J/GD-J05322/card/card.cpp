#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n;
	cin>>n;
	
	int n_2=n;
	
	int i=1;
	
	int b[500005][300005]={0};
	while(n_2--){
		int m;
		cin>>m;
		
		long long a[500005]={0};
		int len=0;
		for (int j=i-1;j<n;j++){
			int x;
			cin>>x;
			int k=0;
			while (k<len){
				if (a[k]==x){
					for (int l=k;l<len;l++){
						a[l]=0;
					}
					len=k;
					break;
				}
				k++;
			}
			if (k==len){
				a[len++]=x;
			}
		}
		
		for (int j=0;j<n;j++){
			b[j][i]=a[j];
		}
		
		i++;
	}
	
	return 0;
}
