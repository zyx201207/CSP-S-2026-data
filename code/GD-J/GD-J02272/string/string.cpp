#include<bits/stdc++.h>
using namespace std;
long long int n,a[200000],ans=0,tot=0;
char b[200000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		tot+=a[i];
	}
		
	long long int j=0,tot2=tot/2;
	bool Jump=0;
	if(tot%2==1)ans++;
	for(int i=0;i<n;i++){
		while(a[i]>0){
			if(b[n-j-1]!=b[i])ans+=min(a[n-j-1],a[i]);
			a[i]-=a[n-j-1];
			tot2-=a[n-j-1];
			if(tot2<=0){
				Jump=1;
				break;
			}
			if(a[i]<0){
				a[n-j-1]-=a[i]*(-1); 
				break;
			}
			j++;
		}
		if(Jump)break;
	}
	cout<<ans;
	return 0;
} 
