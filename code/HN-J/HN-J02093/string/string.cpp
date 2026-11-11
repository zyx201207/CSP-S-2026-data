#include<bits/stdc++.h>
using namespace std;
const long long N=1e7;
string s,b[N],c,d[N],e[N];
long long n,a[N],x,w,z;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
    for(int i=1;i<=n;i++){
    	cin >> a[i] >> b[i];
    	for(int j=1;j<=a[i];j++){
    		s+=b[i];
		}
		x+=a[i];
	}
    for(int i=n;i>=1;i--){
    	for(int j=1;j<=a[i];j++){
    		c+=b[i];
		}
	}
	if(s==c){
		cout << "0";
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			if(b[i]=="a"){
				z++;
			}
		}
		for(int i=1;i<=n;i++){
			if(b[i]=="a"){
				w=z*a[i];
			}
		}
	}
	cout << w;
	return 0;
}
