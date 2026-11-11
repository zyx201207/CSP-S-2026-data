#include<bits/stdc++.h>
using namespace std;
long long n;
string d1,d2;
string z;
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		long long s;
		string s2;
		cin>>s>>s2;
		for(int i=1;i<=s;i++) z+=s2;
	}
	int p=z.size();
	if(p%2!=0){
		for(int i=0;i<p/2;i++){
			d1+=z[i];
		}
		for(int i=p-1;i>p/2;i--){
			d2+=z[i];
		}
		for(int i=0;i<=p/2-1;i++){
			if(d1[i]!=d2[i]) cnt++;
		}
	}
	else{
		for(int i=0;i<p/2;i++){
			d1+=z[i];
		}
		for(int i=p-1;i>=p/2;i--){
			d2+=z[i];
		}
		for(int i=0;i<=p/2;i++){
			if(d1[i]!=d2[i]) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
