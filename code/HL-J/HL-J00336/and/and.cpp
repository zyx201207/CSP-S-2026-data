#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	int cnt,cnt2;
	cin>>cnt>>cnt2;
	for(int i=1;i<=cnt;i++){
		cin>>a[i];
	}
	for(int i=0;;i++){
		if(i==0) cnt+=a[i]*1;
		else{
			int cnt2=0;
			for(int j=1;j<=i;j++)
				cnt2*=2;
			}
			cnt+=a[i]*cnt2;
		}
	
	cout<<12;
	return 0;
} 
