#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],b[200005],fn,len,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>b[i]>>c;
		a[i]=c-97;
	}
	fn=n;
	for(int i=1;i<=fn;){
		if(a[i]==a[fn]){
			if(b[i]>b[fn]){
				b[i]-=b[fn];
				fn--;
			}else if(b[i]<b[fn]){
				b[fn]-=b[i];
				i++;
			}else{
				i++;
				fn--;
			}
		}else{
			if(b[i]>b[fn]){
				b[i]-=b[fn];
				sum+=b[fn];
				fn--;
			}else if(b[i]<b[fn]){
				b[fn]-=b[i];
				sum+=b[i];
				i++;
			}else{
				sum+=b[i];
				i++;
				fn--;
			}
		}
	}
	cout<<sum;
	return 0;
}
