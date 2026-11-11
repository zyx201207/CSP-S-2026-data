#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
int aa[200005];
char c[200005];

int main(){
	//c1.length()
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>aa[i]>>c[i];			
	}
	int k=0;
	for(int i=1;i<=n;i++){
		
		k++;
		if(c[k]!=c[n-i+1]){
			ans+=min(aa[k],aa[n-i+1]);
			if(aa[k]>aa[n-i+1]){
				k+=1;
				aa[k]-=aa[n-i+1];
				aa[n-i+1]=0;
			}
			if(aa[k]<aa[n-i+1]){
				i+=1;
				aa[n-i+1]-=aa[k];
				aa[k]=0;
			}
			if(aa[k]==aa[n-i+1]){
				aa[k]=0;
				aa[n-i+1]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
