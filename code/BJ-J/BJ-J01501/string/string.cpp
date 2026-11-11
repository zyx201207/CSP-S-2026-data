#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int num[n];
	long long ans=0;
	char ch[n];
	
	for(int i=0;i<n;i++){
		cin>>num[i]>>ch[i];
	}
	for(int i=0,j=n-1;i<j;){
			if(num[i]>=num[j]){
				if(ch[i]==ch[j]){
					num[i]-=num[j];
					num[j]=0;
					j--;
				}
				else {
					ans+=num[j];
					num[i]-=num[j];
					num[j]=0;
					j--;
				}
			}
			else{
				if(ch[i]==ch[j]){
					num[j]-=num[i];
					num[i]=0;
					i++;
				}
				else {
					ans+=num[i];
					num[j]-=num[i];
					num[i]=0;
					i++;
				}
			}
	}
	cout<<ans;
	//3 2 a 2 b 1 c
	return 0;
}
