#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
long long a[MAXN]={};
char c[MAXN]={};
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int li=1,ri=n;
	long long ans=0;
	while(li<=ri){
		if(a[li]==a[ri]){
			if(c[li]==c[ri]){
				li++;
				ri--;
				continue;
			}else{
				ans+=a[li];
				li++;
				ri--;
			}
		}else if(a[li]<a[ri]){
			if(c[li]==c[ri]){
				a[ri]-=a[li];
				li++;
			}else{
				ans+=a[li];
				a[ri]-=a[li];
				li++;
			}
		}else if(a[li]>a[ri]){
			if(c[li]==c[ri]){
				a[li]-=a[ri];
				ri--;
				continue;
			}else{
				ans+=a[ri];
				a[li]-=a[ri];
				ri--;
			}
		}
	}
	
	cout<<ans;
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
