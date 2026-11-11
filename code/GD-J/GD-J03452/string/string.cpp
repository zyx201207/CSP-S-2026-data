#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],sum;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}for(int i=1,j=n;i<=j;){
		if(c[i]!=c[j]){
			if(a[i]!=a[j]){
				if(a[i]>a[j]){
					a[i]-=a[j];
					sum+=a[j];
					a[j]=0;
					j--;
				}else{
					sum+=a[i];
					a[j]-=a[i];
					a[i]=0;
					i++;
				}
			}else{
				sum+=a[i];
				a[i]=a[j]=0;
				i++,j--;
			}
		}else{
			if(a[i]!=a[j]){
				if(a[i]>a[j]){
					a[i]-=a[j];
					a[j]=0;
					j--;
				}else{
					a[j]-=a[i];
					a[i]=0;
					i++;
				}
			}else{
				a[i]=a[j]=0;
				i++,j--;
			}
		}
	}cout<<sum;
}
