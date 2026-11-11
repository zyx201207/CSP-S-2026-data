#include<bits/stdc++.h>
using namespace std;
long long num[200002];
char c[200002];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num[i]>>c[i];
	}
	long long ans=0;
	for(int i=0,j=n;i<j;){
		if(c[i]!=c[j]){
			if(num[i]<num[j]){
				ans+=num[i];
				num[j]-=num[i];
				num[i]=0;
			}
			else if(num[i]==num[j]){
				ans+=num[i];
				num[j]-=num[i];
				num[i]=0;
			}
			else{
				ans+=num[j];
				num[i]-=num[j];
				num[j]=0;
			}
		}
		else{
			if(num[i]<num[j]){
				num[j]-=num[i];
				num[i]=0;
			}
			else if(num[i]==num[j]){
				num[j]-=num[i];
				num[i]=0;
			}
			else{
				num[i]-=num[j];
				num[j]=0;
			}
		}
		if(num[i]==0)i++;
		if(num[j]==0)j--;
	}	
	cout<<ans;
	return 0;
}
