#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005],l[100010],r[100010],rr[100010];
long long n,sizeofs,half,counts;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=b[i];
		}
	}
	for(int i=0;i<n;i++){
		sizeofs+=a[i];
	}
	if(sizeofs%2==0) half=sizeofs/2;
	else half=(sizeofs-1)/2;
	for(int i=0;i<half;i++){
		l[i]=s[i];
	}
	if(sizeofs%2==0){
		for(int i=half;i<sizeofs;i++){
			r[i]=s[i];
		}
	}
	else{
		for(int i=half+1;i<sizeofs;i++){
			r[i]=s[i];
		}
	}
	for(int i=0;i<half;i++){
		rr[i]=r[i+half+1];
	}
	for(int j=0;j<half;j++){
		if(l[j]!=rr[j]){
			counts++;
		}
		else continue;
	}
	cout<<counts;
	return 0;
}
