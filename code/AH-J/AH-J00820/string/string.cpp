#include<bits/stdc++.h> 
using namespace std;
long long n,ans,j[27],z=0,b,mx=-2e9;
struct ch{
	int i;
	char c;
}a[500001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].i>>a[i].c;
		z+=a[i].i;
		j[a[i].c -96]+=a[i].i ;
	}
	for(int i=1;i<=26;i++){
		if(mx<j[i]){
			mx=j[i];
		}
	}
	for(int i=1;i<=26;i++){
		if(j[i]==mx){
			b++;
		}
	}
	if(z%2==0){
		if(b>=2){
			cout<<z/2;
		}
		else{
			cout<<mx;
		}
		return 0;
	}
	else{
		cout<<z/2;
	}
	return 0;
}

