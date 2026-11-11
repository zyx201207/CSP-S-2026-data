#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long num[200005]={},n,ans=0;
	char ch[200005]={};
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>ch[i];
	}
	for(int i=1,j=n;i<=j;){
		if(ch[i]==ch[j]){
			if(num[i]<num[j]){
				num[j]-=num[i];
				i++;
			}else if(num[i]>num[j]){
				num[i]-=num[j];
				j--;
			}else{
				i++;
				j--;
			}
		}else{
			if(num[i]<num[j]){
				num[j]-=num[i];
				ans+=num[i];
				i++;
			}else if(num[i]>num[j]){
				num[i]-=num[j];
				ans+=num[j];
				j--;
			}else{
				ans+=num[i];
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}

