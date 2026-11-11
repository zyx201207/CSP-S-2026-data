#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k=0;
	cin>>n;
	int m,s=0;
	char f;
	for(int i=0;i<n;i++){
		cin>>m>>f;
		for(int j=0;j<m;j++){
			a=a+f;
			k++;
		}
	}
	if(k%2==0){
		for(int p=0;p<n-1;p++)
		{
			for(int q=k-1;q>=n;q--){
				if(a[p]!=a[q]){
					s++;
					break;
				}
			}
		}
	}
	else{
		n=(k+1)/2;
		for(int p=0;p<n-1;p++)
		{
			for(int q=k-1;q>=n;q--){
				if(a[p]!=a[q]){
					s++;
					break;
				}
			}
		}
	}
	cout<<s;
	return 0;
}
