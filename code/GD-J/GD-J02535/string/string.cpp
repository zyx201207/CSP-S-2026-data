#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];
long long res;
char s[N];

int main(){
	ios::sync_with_stdio(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int L=1,R=n;
	while(L<R){
		if(s[L]!=s[R]){
			if(a[L]>a[R]){
				res+=a[R];
				a[L]-=a[R];
				R--;
			}
			else if(a[L]==a[R]){
				res+=a[L];
				L++,R--;
			}
			else{
				res+=a[L];
				a[R]-=a[L];
				L++;
			}
		}
		else{
			if(a[L]>a[R]){
				a[L]-=a[R];
				R--;
			}
			else if(a[L]==a[R]){
				L++,R--;
			}
			else{
				a[R]-=a[L];
				L++;
			}
		}
	}
	cout<<res;
	return 0;
} 
