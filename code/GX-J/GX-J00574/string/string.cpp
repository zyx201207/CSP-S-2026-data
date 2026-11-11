#include <bits/stdc++.h>
using namespace std;

int main(){
	
    int n=0;
    cin >> n;
    freopen("string.in","r",stdin);
    freopen("string .out","w",stdout);
    int TT[n-1],jian=n/2,jia=n/2,zhong=0;
    string a[n],zong[10005];
    for (int i=0;i<=n;i++){
		cin >> TT[i]>> a[i];
    }
    for (int i=0;i<=n;i++){
		zong +=a[i]*TT[i];
    }
	if(n%2==0){
	    for(int i=n/2;i>=0;i--){
	       if (zong[jian]!=zong[jia]){
	             zhong++;
	       }
	       jian--;
	       jia++;
	    }
	}
	else if(n%2==1){
	   jian=n/2-1;
	   jia=n/2+1;
	   for (int i=n/2+1;i>=0;i--){
			if(zong[jian]!=zong[jia]){
			    zhong++;
			}
	   }
	}
	cout << zhong;
	return 0;
}
