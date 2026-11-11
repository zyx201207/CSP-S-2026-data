#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int k=n;
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
		if(i!=0){
			if(b[i-1]==b[i]){
				k--;
			}
		}
	}
	if(k==1){
		cout<<"0";
		return 0;
	}else {
		for(int i=0;i<n;i++){
			sum+=a[i]/2;
		}
	}
	cout<<sum;
	return 0;
} 
