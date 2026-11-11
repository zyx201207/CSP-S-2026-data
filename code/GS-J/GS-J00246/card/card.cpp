#include<bits/stdc++.h>
using namespace std;
int a[200010];
char b[200010];
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string,out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		cin >> b[i];
	}
	int u=0;
	for(int i=1;i<=n;i++){
		if(b[i]=b[i-1]){
		    a[i]=a[i]+a[i+1];
		    for(int j=i;j<=(n-1);j++){
		    	a[j]=a[j+1];
		    	b[j]=b[j+1];
			}
			n--;
		}
	}
	for(int i=1,j=n/2+(n/2+n%2);i<=(n/2+n%2);i++,j--){
		if((a[i]!=a[j]||b[i]!=b[j])&&(j!=1&&i!=1&&n!=1))u=u+a[i];	
	}
	cout << u; 
	return 0;
}

