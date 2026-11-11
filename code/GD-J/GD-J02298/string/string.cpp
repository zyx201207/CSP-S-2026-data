#include<bits/stdc++.h>
using namespace std;
long long sum,n,sssum,m,ssum,lll;
long long o;
char s[100010];
long long arr[100010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		cin>>s[i];
		sum+=arr[i];
	}
	for(int i=1;i<=n/2+1;i++){
		for(int j=n-lll;j>=i;j--){
			bool p=0,pp=0;
			ssum+=arr[j];
			o++;
			if(s[i]!=s[j]){
				sssum+=arr[j];
				p=1;
			}
			if(ssum<arr[i]){
				arr[j]=0;
			}
			if(ssum>=arr[i]){
				if(o!=1&&ssum!=arr[i]){
					arr[j]-=ssum-arr[i];
				}
				else{
					arr[j]=0;
				}
				o=0;
				ssum=0;
				pp=1;
			}
			if(p&&pp){
				sssum-=arr[j];
			}

			if(arr[j]==0){
				lll++;
			}
			if(pp){
				i++;
			}
		}
	}
	cout<<sssum;
	return 0;
}
