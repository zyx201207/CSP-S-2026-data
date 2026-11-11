//Trick||Treat!
#include<bits/stdc++.h>
using namespace std;
int n,cnt=1,ss,r,ans,l,num;
struct o{
	int a;
	int b;
	char d;
}c[5005];
int main(){
	freopen("string.in","r",stdin); 
    freopen("string.out","w",stdout);
	cin>>n;
	l=n;
	for(int i=1;i<=n;i++){
		cin>>ss;
		c[i].a=cnt;
		cnt+=ss;
		c[i].b=cnt-1;
		cin>>c[i].d;}
	num=cnt-1;
	cnt=0;
	r=1;
	while(r<l){
		ans+=(c[r].b-c[r].a+1);
		while(c[l].a+c[r].b>num){
			if(c[l].d==c[r].d) ans-=(c[l].b-c[l].a+1);
			l--;
		}
		if(c[l].b+c[r].a-1>=num&&c[l].d==c[r].d){
		 ans-=(c[l].b+c[r].b-num);}
		r++;}
	cout<<ans;
	return 0;
}
