#include<bits/stdc++.h>
using namespace std;
long long n,z,cnt;
string a,c;
bool isOK(string a){
	int k=a.size();
	for(int i=0;i<=k/2;i++){
		if(a[i]!=a[k-i-1]){
			return 0;
		}
	}
    return 1;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
		cin>>z>>c;
		for(int j=0;j<z;j++){
			a+=c;
		}
	}
	if(isOK(a)){
		cout<<"0";
		return 0;
	}
	int m=a.size();
    for(int i=0;i<=m/2;i++){
		if(a[i]!=a[m-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
    return 0;
}
