#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
const int N=2e5+10;
int n;
ll an1=0,anss=0;
int a[N],a2[N];
char b[N],b2[N];
string s,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		a2[n-i-1]=a[i],b2[n-i-1]=b[i];
		an1+=1ll*a[i];
		while(a[i]--){
			s+=b[i];
		}
	}
	for(int i=0;i<n;i++){
		while(a2[i]--){
			s2+=b2[i];
		}
	}
	for(int i=0;i<an1;i++){
		if(s[i]!=s2[i]){
			anss++;
		}
	}
	cout<<anss/2;
	return 0;
}
