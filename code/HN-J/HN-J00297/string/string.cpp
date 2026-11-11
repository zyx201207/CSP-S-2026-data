#include<bits/stdc++.h>
using namespace std;
int n;
int m;
char a;
char h[1000005];
int x=1;
int t=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>a;
		for(int j=1;j<=m;j++){
			h[x]=a;
			x++;
		}
	}
	x-=1;
	for(int i=1;i<=x/2;i++){
		if(h[i]!=h[x+1-i]) t++;
	}	
    cout<<t;
    //cout<<x;
	//for(int i=1;i<=x;i++){
	//	cout<<h[i];	
	//}
	
	
	return 0;
}

