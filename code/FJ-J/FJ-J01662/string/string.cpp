#include<bits/stdc++.h>
using namespace std;
struct node{
	long long l,r,lens;
	char a;
}s[200005];
long long len;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a;
	char b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		len+=a;
		s[i].l=len+1;
		s[i].r=len+a;
		s[i].a=b;
		s[i].lens=s[i].r-s[i].l+1;
	}
	//---------------------------------------------
	long long midk,midb;
	if(len%2==1){
		midk=(len+1)/2;
		for(int i=1;i<=n;i++){
			if(s[i].l<=midk&&s[i].r>=midk) {
				midb=i;
				break;
			}
		}
	}
	if(len%2==0){
		midk=len/2;
		for(int i=1;i<=n;i++){
			if(s[i].l<=midk&&s[i].r>=midk) {
				midb=i;
				break;
			}
		}
	}
	//------------------------------------------
	long long ans=0,i=1,j=n;
	while(i<=j){
		//cout<<i<<' '<<j<<' '<<ans;
		if(s[i].lens>s[j].lens) {
			if(s[i].a==s[j].a){
				s[i].l+=s[j].lens,s[i].lens-=s[j].lens,j--;
			}
			else if(s[i].a!=s[j].a){
				s[i].l+=s[j].lens,s[i].lens-=s[j].lens,ans+=s[j].lens,j--;
			}
		}
		if(s[i].lens<s[j].lens) {
			if(s[i].a==s[j].a){
				s[j].r-=s[i].lens,s[j].lens-=s[i].lens,i++;
			}
			else if(s[i].a!=s[j].a){
				s[j].r-=s[i].lens,s[j].lens-=s[i].lens,ans+=s[i].lens,i++;
			}
		}
		if(s[i].lens==s[j].lens) {
			if(s[i].a==s[j].a){
				i++,j--;
			}
			else if(s[i].a!=s[j].a){
				ans+=s[j].lens,i++,j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
