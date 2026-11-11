#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;cin>>n;
	int num[n];
	char vec[n];
	for(int i=0;i<n;i++){
		cin>>num[i];
		cin>>vec[i];
	}
	int i=0,j=n-1;
	while(i<=j){
		if(vec[i]!=vec[j]){
			ans+=min(num[i],num[j]);
	    }
		if(num[i]>num[j]){
			num[i]=num[i]-num[j];
			j--;
			continue;
		} 
		if(num[i]<num[j]){
			num[j]=num[j]-num[i];
			i++;
			continue;
		}
		if(num[i]==num[j]){
			i++;
			j--;
			continue;
		}
	}
	cout<<ans;
	return 0; 
}
/*
5
2 a
2 b
2 c
1 a
1 d
*/
