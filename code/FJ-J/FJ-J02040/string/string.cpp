#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],t[50],cnt,sum,l;
char c[200005];
string s;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(sum<=l/2)t[c[i]-'a']+=a[i];
		if(sum>l/2){
			if(sum-a[i]<l/2){
				t[c[i]-'a']+=l/2-(sum-a[i]);
				t[c[i]-'a']-=a[i]-(l/2-(sum-a[i]));
			}
			else{
				t[c[i]-'a']-=a[i];
			}
		}
	}
	for(int i=0;i<=25;i++){
		if(t[i]>0)cnt+=t[i];
	}
	cout<<cnt;
	return 0;
}
