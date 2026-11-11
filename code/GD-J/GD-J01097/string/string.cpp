#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=2e5+5;
int n,cnt,L_len,R_len;
ll len,ans;
struct str{
	ll a;
	char c;
}s[N],l[N],r[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll _a;
		char _c;
		cin>>_a>>_c;
		len+=_a;
		if(_c==s[cnt].c)s[cnt].a+=_a;
		else s[++cnt].a=_a,s[cnt].c=_c;
	}
	n=cnt;
	cnt=0;
	ll sum=0;
	char p='l';
	for(int i=1;i<=n;i++){
		if(sum+s[i].a<=len/2){
			sum+=s[i].a;
			l[++L_len].a=s[i].a;
			l[L_len].c=s[i].c;
		}
		else if(p=='l'){
			p='r';
			if(len/2-sum>0)
			l[++L_len].a=len/2-sum,l[L_len].c=s[i].c;
			if(len%2==0)
			r[++R_len].a=s[i].a-(len/2-sum);
			else r[++R_len].a=s[i].a-1-(len/2-sum);
			r[R_len].c=s[i].c;
			sum=len/2+1; 
		}else {
			r[++R_len].a=s[i].a;
			r[R_len].c=s[i].c;
		}
	}
	//--------------------------------
	
	for(int i=1,j=R_len;i<=L_len,j>0;){
		if(l[i].c!=r[j].c){
			if(l[i].a<r[j].a){
				ans+=l[i].a;
				r[j].a-=l[i].a;
				i++;
			}else {
				ans+=r[j].a;
				l[i].a-=r[j].a;
				j--;
				if(l[i].a==0)i++;
			}
		}else {
			if(l[i].a<r[j].a){
				//ans+=l[i].a;
				r[j].a-=l[i].a;
				i++;
			}else {
				//ans+=r[j].a;
				l[i].a-=r[j].a;
				j--;
				if(l[i].a==0)i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
