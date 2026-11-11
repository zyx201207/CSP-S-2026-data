#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0,c;
    long long a[200001];
    char b[200001];
    cin>>n;
    int n1=0,n2=n;
    for(int i=0;i<n;i++){
    	cin>>a[i]>>b[i];
	}
	n2--;
	while(1){
		c=(max(a[n1],a[n2])-min(a[n1],a[n2]));
		if(b[n1]!=b[n2]){
			if(a[n1]>a[n2]){
				ans+=a[n2];
				a[n1]=c;
				n2--;
			}else if(a[n1]==a[n2]){
				ans+=a[n1];n1++;n2--;
			}else{
				ans+=a[n1];
				a[n2]=c;
				n1++;
			}
		}else{
			if(a[n1]>a[n2]){
				a[n1]=c;
				n2--;
			}else if(a[n1]<a[n2]){
				a[n2]=c;
				n1++;
			}else{
				n1++;
				n2--;
			}
		}
		if(n1>=n2){
			break;
		}
	}
	cout<<ans;
	return 0;	
}
