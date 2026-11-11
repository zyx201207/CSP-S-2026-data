#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[200020];
	char b[200020];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	long long i=1,bj=n,z=0;
	while(i<=bj){
		if(b[i]!=b[bj]){
			if(a[i]==a[bj]){
				z+=a[i];
				//b[bj]=b[i];
				i++;
				bj--;
				
			}
			else if(a[i]>a[bj]){
				z+=a[bj];
				//b[bj]=b[i];
				a[i]-=a[bj];
				bj--;
			}
			else{
				z+=a[i];
				a[bj]-=a[i];
				i++;
			}
		}
		else{
			if(a[i]==a[bj]){
				i++;
				bj--;
			}
			else if(a[i]>a[bj]){
				a[i]-=a[bj];
				bj--;
			}
			else{
				a[bj]-=a[i];
				i++;
			}
		}
	}
	cout<<z;
    return 0;
} 
