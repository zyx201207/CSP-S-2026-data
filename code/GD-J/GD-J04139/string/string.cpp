#include<bits/stdc++.h> 
using namespace std;
int n,sum=0;
int a[200005];
string c,bh,nbh;
int p=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		int j;
		if(i==0){
			j=0;
		}
		for(;j<a[i];j++){
			bh[i+j]=c[i+j];
			
		}
	}
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	for(int i=sum-1;i>=0;i--){
		int j=0;
		nbh[j]=bh[i];
		j++;
	}
	if(nbh==bh){
		cout<<0;
		return 0;
	}
	else{
		int j=n;
		for(int i=0;i<=n/2;i++){
			j--;
			if(nbh[i]=nbh[j]){
				nbh[i]=nbh[j];
			}
			else{
				nbh[i]=nbh[j];
				p++;
			}
		}
	}
	cout<<p;
	return 0;
}
