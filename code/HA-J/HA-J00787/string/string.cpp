#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	cin.tie(0);cout.tie(0);
	long long n,su=0,aa=0;cin>>n;int x[n];char a[n];memset(x,0,sizeof(x));memset(x,0,sizeof(x));//string str="";
	for(int i=0;i<n;i++){
		cin>>x[i]>>a[i];su+=x[i];
	}
	long long l=0,r=su-1,le=0,ri=n-1;
	while(l<=((su+1)/2-1)){
		if(x[le]==x[ri]){
			if(a[le]!=a[ri]) aa+=x[le];
			l+=x[le];r-=x[le];le++;ri--;
		}
		else{
			if(a[le]!=a[ri]){
				aa+=min(x[le],x[ri]);
			}
			l+=min(x[le],x[ri]);r-=min(x[le],x[ri]);
			if(x[le]>x[ri]){
				x[le]=x[le]-x[ri];ri--;
			}
			else{
				x[ri]-=x[le];le++;
			}
		}
	}
	cout<<aa;
	return 0;
}
