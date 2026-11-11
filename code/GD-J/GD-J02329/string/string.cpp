#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
string s,ns;
int n,nm;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	int ct=0,y=0,x=1;
	
	for (int i=0;i<n;i++){
		cin >> a[i];
		cin >> s[i];
	}//输入； 
	for(int i=n-1;i>=0;i--){
		ns[ct]=s[i];
		ct++;
	}//回文； 
	
	
	for(int i=0;i<n-1;i++){
			if(a[i]!=a[i+1]){
				y=1;
				break;
			}
		}//if数字==; 
		
	for(int i=0;i<n-1;i++){
			if(s[i]==s[i+1]){
				x=0;
				break;
			}
		}//if字母==; 
	
	if(x==0){
		cout<<0;}
		
	else if(y==0){
		for(int i=0;i<n/2;i++){
			if(s[i]!=ns[i]) nm++;
		}
		nm=nm*a[0];
		cout << nm;
	}
	else{
		for(int i=0;i<n/2;i++){
				if(s[i]!=ns[i]){
					nm+=a[i]; 
				}
			}
		cout << nm;}
	return 0;
} 
