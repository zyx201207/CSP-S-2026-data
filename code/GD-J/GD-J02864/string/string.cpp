#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
int n;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	ll cnt=0;
	while(i<=j){
		if(c[i]!=c[j]){
			if(a[i]!=a[j]){
				cnt+=min(a[i],a[j]);
				if(a[i]>a[j]){
					a[i]-=a[j];
					j--;
				}else{
					a[j]-=a[i];
					i++;
				}
			}else{
				cnt+=a[i];
				i++,j--;
			}
		}else{
			if(a[i]!=a[j]&&i+1!=j){
				if(a[i]>a[j]){
					a[i]-=a[j];
					j--;
				}else{
					a[j]-=a[i];
					i++;
				}
			}
			else{
				i++,j--;
			}
		}
	}
	cout<<cnt<<"\n";
	return 0;
} 
