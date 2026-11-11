#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	char c[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<n;j++){
			cin>>c[j];
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(c[i]=c[i+1]){
			cout<<"0";
			break;
		}else{
			cnt+=a[i];
			cout<<(cnt+1)/2;
		}
	}
	return 0;
}
