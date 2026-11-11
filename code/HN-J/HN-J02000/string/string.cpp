#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,wen;
string b,s,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n%2==0){
		wen=n/2+1;
	}else{
		wen=n/2+1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=n;i>=1;i--){
		t=a[i];
		s=b[i];
	}
	for(int i=1,j=1;;){
		if(b[i]!=s[j]){
			if(a[i]<t[j]){
				ans=ans+t[j];
				a[i]-=t[j];
				j++;
			}else if(a[i]>t[j]){
				ans=ans+a[i];
				t[j]-=a[i];
				i++;
			}else{
				ans+=t[j];
				i++,j++;
			}
		}
		if(i==wen || j==wen){
			cout<<ans;
			return 0;
		}else if(i==wen || j==wen){
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
