#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll num[100000005];
char word[100000005];
//char w[1000000005];
char c[100000005];
ll tot=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	int a=1;char l=' ';
	for(ll i=1;i<=n;i++){
		cin>>num[i]>>word[i];
		c[word[i]]+=num[i];
		if(i==1){
			l=word[i];
		}
		else if(i!=1&&l!=word[i]){
			l=word[i];
			a++;
		}
		tot+=num[i]; 
	}
	ll ssize=tot/2;
	if(a==1){
		cout<<0;
		return 0;
	}
	int j=1;
	for(int i=1;i<=tot;i++){
		if(num[j]==0){
			j++;
		}
		c[i]=word[j];
		num[j]--;
	}
	for(int i=1;i<=ssize;i++){
		if(c[i]!=c[tot-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
