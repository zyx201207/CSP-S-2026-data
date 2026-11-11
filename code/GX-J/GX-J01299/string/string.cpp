#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in",'r',stdin);
	freopen("string.out",'w',stdout);
	long long n,c[300005],ans=0;
	char a[300005];
	cin>>n;
	for(int i=1;i<=n;i++) cin>>c[i]>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]!=a[n-i+1]){
			while(c[i])
				if(c[i]>c[n-i+1]){
					ans+=c[n-i+1];
					c[i]-=c[n-i+1];
					n--;
			}else{
				ans+=c[i];
				c[n-i+1]-=c[i];
				i++;
				if(!c[n-i+1]) n--;
				break;
			}
		}else{
			if(c[i]>c[n-i+1]){
				c[i]-=c[n-i+1];
				n--;
			}else{
				ans+=c[i];
				c[n-i+1]-=c[i];
				i++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
