#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	long long n[a];
	for(int i=0;i<=a-1;i++){
		cin>>n[i];
	}
	if(a==1){
		cout<<1;
		return 0;
	}
	if(b==1){
		for(int i=0;i<=a-1;i++){
			cout<<n[i]<<" ";
		}
	}
	if(a==2){
		cout<<n[0]<<" "<<n[1];
		return 0;
	}
	return 0;
}
