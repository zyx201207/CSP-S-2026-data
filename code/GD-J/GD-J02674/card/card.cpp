#include <bits/stdc++.h>
using namespace std;
long long n,m,num[100005];
long long a[1000005],b[1000005];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin >>n;
	cin >>m;
	for(int i=1;i<=m;i++){
		num[i]=i;
	}
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	int c,d;
	for(int o=1;o<=n;o++){
		for(int i=o;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[i]==a[j]){
					for(int k=i+1;k<=j;k++){
						c=i;
						d=j;
						b[k]=a[k];
						a[k]=0;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			num[a[i]]++;
		}
		for(int i=c;i<=d;i++){
			a[i]=b[i];
		}
	}
	for(int i=1;i<=m;i++){
			cout<<num[i]<<" ";
		}
	return 0;
}
