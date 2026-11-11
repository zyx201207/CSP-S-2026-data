//GZ-J00253 华东师范大学附属贵阳学校 袁琬潇 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s,s2;
long long a[N],n;
long long cnt;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>s[i];
	for(int i=1,j=n;;){
		if(a[i]>=a[j]){
			if(s[i]!=s[j]) cnt+=a[j];
			a[i]-=a[j];
			j--;
			if(a[i]<=0) i++;
		}else{
			if(s[i]!=s[j]) cnt+=a[i];
			i++;
			a[j]-=a[i];
			if(a[j]<=0) j--;
		}
		if(i>n/2||j<n/2) break;
	}
	cout<<cnt<<endl; 
	return 0;
}
