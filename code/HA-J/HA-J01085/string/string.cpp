#include<bits/stdc++.h>
using namespace std;
int n;
char a[10000005];
int b;
char c;
int x=1;
int sum=0;
int q=0;
int main(){
	freopen(string.in,"r",stdin);
	freopen(string.out,"w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b;
		cin>>c;
		for(int j=1;j<=b;j++){ 
			a[x]=c;
			x+=1;
			q++;
		}
	}
	for(int i=1;i<=q;i++){
		if(a[i]!=a[q+1-i]){
			a[q+1-i]=a[i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
