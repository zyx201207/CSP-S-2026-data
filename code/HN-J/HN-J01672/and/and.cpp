#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,s,b[100000];
	cin>>a>>s;
	for(int i=0;i<a;i++){
		cin>>b[i];
	} 
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			if(b[i]>b[j]){
				swap(b[i],b[j]);
			}
		}
	}
	int ans=b[0];
	for(int i=1;i<s;i++)ans=ans&b[i];
	cout<<ans;
	return 0; 
}
