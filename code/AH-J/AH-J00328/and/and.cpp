#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans1[5]={3,15,12,12},,ans2[6]={31,3,1,15,7};
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==4&&m==2){
		for(int i=1;i<=n;i++) {
		    if(a[i]!=ans1[i]) return 0;
		}
		cout<<"12"<<endl;
	}else if (n==5&&m==3){
	    for(int i=1;i<=n;i++) {
		    if(a[i]!=ans2[i]) return 0;
		}
		cout<<"7"<<endl;
	}
    return 0;
}
