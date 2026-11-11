#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005],h[400005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n,c=0,s=0,d;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
		    c++;
			h[c]=b[i];
		}
	}
	d=c;
	for(int i=1;i<=d/2;i++){
		if(n%2==1&&c==i){
			break;
		}
		if(h[c]!=h[i]){
			h[c]=h[i];
			c--;
		    s++;
		}
	}
	cout<<s;
	return 0;
}
