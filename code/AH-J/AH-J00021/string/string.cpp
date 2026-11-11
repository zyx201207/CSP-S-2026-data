#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long t,a[200010],ans=0;
	char b[200010];
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a[i]>>b[i];
	}
	int z1=1,z2=t,l1=a[1],l2=a[t];
	while(z2>z1){
		if(b[z1]==b[z2]){
			if(l1>l2){
				l1-=l2;
				z2--;
				l2=a[z2];
			}
			else if(l1<l2){
				l2-=l1;
				z1++;
				l1=a[z1];
			}
			else{
				z1++;
				z2--;
				l1=a[z1];
				l2=a[z2];
			}
		}
		else{
			if(l1>l2){
				ans+=l2;
				l1-=l2;
				z2--;
				l2=a[z2];
			}
			else if(l1<l2){
				ans+=l1;
				l2-=l1;
				z1++;
				l1=a[z1];
			}
			else{
				ans+=l2;
				z1++;
				z2--;
				l1=a[z1];
				l2=a[z2];
			}
		}
	}
	cout<<ans;
}
