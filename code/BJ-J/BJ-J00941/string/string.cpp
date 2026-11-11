#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a;
    int n,s,pos=-1,cnt=0;
    cin>>n;
    char c;
    for(int i=1;i<=n;i++){
		cin>>s>>c;
		for(int j=pos+1;j<=pos+s;i++) a+=c;
		pos+=s;
	}
	if(pos%2==0){
		for(int i=0;i<=pos/2;i++){
			for(int j=pos;j>=pos/2;j--){
				if(a[i]!=a[j]) cnt++;
			}
		}
	}
	else{
		for(int i=0;i<=pos/2;i++){
			for(int j=pos;j>=pos/2+1;j--){
				if(a[i]!=a[j]) cnt++;
			}
		}
	}
	cout<<cnt;
    return 0;
}
