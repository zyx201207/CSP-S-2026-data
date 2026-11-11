#include<bits/stdc++.h>
using namespace std;
long long int n,a[1000000],sum,ans,l,r,R;
char c[1000000];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		
	}
	R=n;
	for(int i=1;i<=n;){
		if(R>i){
			if(a[R]>a[i]){
				if(c[i]!=c[R]){
					ans+=a[i];
				}
				a[R]-=a[i];
				i++;
			}else if(a[i]>a[R]){
				if(c[i]!=c[R]){
					ans+=a[R];
				}
				a[i]-=a[R];
				R--;
			}
		}else{
			break;
		}	
	}
	cout<<ans<<endl;
	return 0;
}
