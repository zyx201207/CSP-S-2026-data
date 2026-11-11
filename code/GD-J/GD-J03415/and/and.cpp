#include <bits/stdc++.h>
using namespace std;
int n,n2,n3,m;
long long a[200005],a1[200005],a2[200005],ans;
int b[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	n3=n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		for (int j=31;j>=0;j--){
			if((1<<j) & a[i]){
				b[j]++;
			} 
			
		}
		a1[i]=a[i];
	}
	for (int j=31;j>=0;j--){
		if(b[j]>=m){
			n2=j;
			break;
		}
	}
	
	for (int j=n2;j>=0;j--){
		int l=1,ln=0;
		for(int i=1;i<=n3;i++){
			if(a1[i] & (1<<j)){
				a2[l++]=a1[i];
				ln++;
			}
		}
		if(ln>=m){
			ans+=(1<<j);
		}
		n3=ln;
		swap(a1,a2);
	}
	cout<<ans;
	return 0;
} 
