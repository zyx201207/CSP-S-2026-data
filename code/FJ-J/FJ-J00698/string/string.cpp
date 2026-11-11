#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long cnt=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>a[i]>>b[i];
		cnt+=a[i];
    }
    long long a1[cnt];
    for(int i=1;i<=cnt/2;i++){
    	if(a1[i]!=a1[cnt-i+1]){
    		ans++;
		}
	}
	cout<<ans;
    /*
    if(allhw==true) cout<<0;
    else{
    	cout<<cnt/2;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[n-i-1]&&b[i]==b[n-i-1]){
		   continue;
		}else if(a[i]>a[n-i-1]){
			cnt+=a[i]-a[n-i-1];
			
		}
	}
	*/
	
	return 0;
}
/*
5
1 a
4 b
4 c
3 a
4 c

*/
