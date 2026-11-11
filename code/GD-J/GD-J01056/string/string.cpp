#include<bits/stdc++.h>
using namespace std;
long long n,sum=1,lens,ans;
string a;
int main(){
	freopen("string.in","r",stdin);
  	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	long long s;string c;
    	cin>>s>>c;
    	for(int j=sum;j<=sum+s;j++){
    		a+=c;
		}
		sum+=s;
	}
	cout<<sum<<endl;
	for(int i=1;i<=sum/2;i++){
		if(a[i]!=a[sum+1-i]){
			ans++;
			cout<<a[i]<<" "<<a[sum+1-i]<<endl;
		}
	}
	cout<<ans;
    return 0;
}

