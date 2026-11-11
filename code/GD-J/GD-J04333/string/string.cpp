#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	int n=0,sum=0,jc=0,zc=0;
	cin >> n;
	string a="", b="", a1="", a2="";
	for(int i=0;i<n;i++){
		cin >> jc >> b;
		zc += jc; 
		for(int j=0;j<jc;j++) a += b;
		b = "",jc=0;
	}
	
	if(zc%2==0){
		for(int i=0;i<zc;i++){
			if(i < zc/2) a1 += a[i];
			else a2 += a[i];
		}
	}
	else if(zc%2==1){
		for(int i=0;i<zc;i++){
			if(i < zc/2) a1 += a[i];
			else if(i > zc/2) a2 += a[i];
		}
	}
	
	if(a1==a2){
		cout << 0 << endl;
		return 0;
	}
	
	for(int i=0;i<zc/2;i++){
		if(a1[i] == a2[i]) continue;
		else sum++;
	}
	
	cout << sum << endl;
	return 0;
}
