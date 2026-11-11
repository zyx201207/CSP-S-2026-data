#include<bits/stdc++.h>
using namespace std;
int n,w,cnt;
int a[100010];
string c[100010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
	}
    if(n==1){
    	cout<<0;
	}
	if(n==0){
    	cout<<0;
	}
	
	if(n==2){
    	if(c[1]==c[2]){
		cout<<0;
	    }else{
	    	cout<<1;
		}
	}
	if(n%2==1){
		w=n/2+1;
	}else{
		w=n/2;
	}
    if(n>=2){
    	for(int j=1;j<=w;j++){
    		if(c[j]!=c[n-j+1]){
    			cnt++;
			}
		}
	}
	
    cout<<cnt;
	
	return 0;
}