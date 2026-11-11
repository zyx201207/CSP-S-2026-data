#include<bits/stdc++.h>
using namespace std;
int n;
long long sum=0,ans=0;
int a[200005];
char ch[200005]; 
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		sum+=a[i];
	}
	sum/=2;
	int k1=1,now1=1,k2=n,now2=a[n];
	for(int l=1;l<=sum;l++){
		if(now1>a[k1]){
			now1=1;
			k1++;
		}
		if(now2==0){
			now2=a[k2-1];
			k2--;
		}
		char p1=ch[k1];
		char p2=ch[k2];
		if(p1!=p2){
			ans++;
		}
		now1++;
		now2--;
	}
	cout<<ans;
	return 0;
} 
