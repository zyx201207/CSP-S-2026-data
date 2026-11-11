#include<bits/stdc++.h>
using namespace std;
long long a[1000000],al,ar;
long long ans;
int n;
string s[1000000],sl,sr;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>s[i];
	}
	sl=s[1];
	sr=s[n];
	al=1;
	ar=n;
	while(al<ar){
		if(a[al]<a[ar]){
			if(sl!=sr){
				ans+=a[al];
			}
			a[ar]-=a[al];
			al++;
			sl=s[al];
		}
		else if(a[al]>a[ar]){
			if(sl!=sr){
				ans+=a[ar];
			}
			a[al]-=a[ar];
			ar--;
			sr=s[ar];
		}
		else {
			if(sl!=sr){
				ans+=a[ar];
			}
			al++;
			ar--;
			sl=s[al];
			sr=s[ar];
		}
	}
	cout<<ans;
	return 0;
} 
