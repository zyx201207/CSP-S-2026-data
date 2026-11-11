#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int a[N],f[N];
int main(){
ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}

	int cnt=0,i=1,j=1;
	for(char c:s1){
		a[i]=(int)c;
		i++;
	}
	for(char b:s2){
		f[j]=(int)b;
		j++;
	}

	for(int i=1;i<=2;i++){
		if(a[i]==f[i]){
			cnt++;
			if(cnt==2){
				cout<<"1";
			}
		}else {
			cout<<"000";
			return 0;
		}
	}
	if(a[3]>='A'&&a[3]<='C'&&f[3]>='A'&&f[3]<='C'){
		cout<<"1";
		if(a[3]+1==f[3]||f[3]+1==a[3]){
		cout<<"1";
		return 0;
		}else{
		cout<<"0";
		return 0;
		}
	}else if(a[3]>='D'&&a[3]<='F'&&f[3]>='D'&&f[3]<='F'){
		cout<<"1";
		if(a[3]+2==f[3]||f[3]+2==a[3]){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"00";
		return 0;
	}
	return 0;
} 
