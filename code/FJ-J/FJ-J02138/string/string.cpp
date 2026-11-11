#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string h;
    int n,m=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    	int d;
    	char g;
    	cin>>d>>g;
    	for(int j=1;j<=d;j++){
    		h+=g;
    	}
    }
    int y=n;
    for(int i=1;i<=n;i++){
    	if(h[i]!=h[i+y-1]){
    		m+=1;
    	}
    	y-=2;
    }
	cout<<m;
} 
