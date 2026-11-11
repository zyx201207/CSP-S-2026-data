#include<bits/stdc++.h>
using namespace std;
const int M=1e5*2+10;
long long n,l,cnt,a[M],ord;
char s[M];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a[ord+1]>>s[++ord];
		l+=a[ord];
	}
	int L=1,R=ord;
	while(1){
		if(L>=R)break;
		if(s[L]==s[R]){
			if(a[L]<a[R]){
				a[R]-=a[L];
				L++;
			}
			else if(a[L]==a[R]){
				L++;
				R--;
			}
			else{
				a[L]-=a[R];
				R--;
			}
		}
		else{
			if(a[L]<a[R]){
				cnt+=a[R]-a[L];
				a[R]-=a[L];
				L++;
			}
			else if(a[L]==a[R]){
				cnt+=a[L];
				L++;
				R--;
			}
			else{
				cnt+=a[L]-a[R];
				a[L]-=a[R];
				R--;
			}
		} 
	}
	cout<<cnt;
	return 0; 
} 
