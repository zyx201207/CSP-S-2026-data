#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],c;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	long long l=1,l1=1,r=1,r1=n;
	while(l1<=r1||l<r){
		if(l>a[l1]){
			l1++;
			l=1;
		}
		if(r>a[r1]){
			r1--;
			r=1;
		}
		if(s[l1]!=s[r1]){
			c++;
		}
		l++,r++;
	}
	if(c==0){
		cout<<0;
	}else{
		cout<<c-1;
	}
    return 0;
}
