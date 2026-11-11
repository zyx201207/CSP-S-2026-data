#include<bits/stdc++.h>
using namespace std;
int s=0;
int a[100000010];
int aa=0;
int n;
int m;
int main(){
	freopen("crystal.in","r",stdin)
	freopen("crystal.out","w",stdout)
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]!=a[i+1]){
			aa=a[i+1]-a[i];
			m=m-(aa*i);
			for(int j=0;j<i;j++){
				a[j]=a[i];
			}
		}
		if(m<=0){
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1]){
			s++;
		}
	}
	cout<<s+1;
}


