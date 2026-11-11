#include <bits/stdc++.h>
using namespace std;
int n,m;
int a,b,c=1;
int mz[100];
int anum,bnum,num=1,num2[100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","W",stdout);
	cin>>n>>m;
	if(m==1){
		cout<<n;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a;
			if(i==1){
				b+=a;
				anum++;
			}
			if(a==b){
				anum++;
			}
			else{
				bnum++;
			}
			
		}
		if(bnum>1){
			cout<<bnum-1<<" ";
		} 
		if(anum>1){
			cout<<anum-1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>mz[i];
		if(mz[i]>mz[i-1]){
			num++;
			c++;
		}
		else if(mz[i]==mz[i-1]){
			num2[c]++;
		}
	}
	if(num==n){
		return 0;
	}
	else if(num2[c]==n){
		cout<<n;
		return 0;
	}
	else{
		for(int i=1;i<=c;i++){
			if(num2[i]>1){
				cout<<num2[i]-1<<" ";
			}
		}
		return 0;
	}
	return 0;
}
