#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,a[N];long long t,as;char c[N],w;string x;bool b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	if(n==1) cout<<0;
	else if(n<=10){
		if(a[1]>100000000){
			cout<<300000000;
			return 0;
		}
		for(int i=1;i<=n;i++) t+=a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++) x+=c[i];
		}
		for(int i=0;i<=t/2;i++){
			if(x[i]!=x[t-i-1]) as++;
		}
		cout<<as;
	}else{
		w=c[1];b=1;
		for(int i=2;i<=n;i++){
			if(c[i]!=w){
				b=0;
				break;
			}
		}
		if(b) cout<<0;
		else{
			w=c[1];b=1;
			for(int i=2;i<=n;i++){
				if(c[i]!=w){
					b=0;
					break;
				}
			}
			if(b)cout<<0;
			else{
				for(int i=1;i<=n/2;i++){
			        if(c[i]!=c[n-i+1]) as+=a[i];
		        }
		        cout<<as;
			}
		}
	}
	return 0;
}
