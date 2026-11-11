#include<bits/stdc++.h>
using namespace std;
char a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,m,k=1,o=0,l=0;
	char b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>b;
		o=o+m;
		for(int j=k;j<=o;j++){
			a[j]=b;
			k++;
		}
	}
	n=0;
	if(m%2==1){
		for(int i=m/2+2,l=2;i<=o;i++,l=l+2){
				if(int(a[i])!=int(a[i-l])){
					n++;
			    }
		    }
		}
	else{
		for(int i=m/2+1,l=1;i<=o;i++,l=l+2){
				if(int(a[i])!=int(a[i-l])){
					n++;
				}
			}
		}
	cout<<n-2;
	
	return 0;
}
