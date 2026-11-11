#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	long long qw,a[200005]={},top=0,cnt=0;
	string s;
	char op[200005];
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>qw>>op[top+1];
		if(op[top]==op[top+1]){
			a[top]+=qw;
		}else{
			top++;
			a[top]=qw;
		}
		cnt+=qw;
	}
	int li=1,ri=T;
	long long ans=0;
	while(li<=ri){
		if(op[li]==op[ri]){
			if(a[li]==a[ri]){
				li++,ri--;
			}else if(a[li]<a[ri]){
				a[ri]-=a[li];
				li++;
			}else{
				a[li]-=a[ri];
				ri--;
			}
		}else{
			if(a[li]==a[ri]){
				ans+=a[li];
				li++,ri--;
			}else if(a[li]<a[ri]){
				ans+=a[li];
				a[ri]-=a[li];
				li++;
			}else{
				ans+=a[ri];
				a[li]-=a[ri];
				ri--;
			}
		}
	}
	cout<<ans;
	
}
