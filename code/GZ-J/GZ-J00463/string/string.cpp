//GZ-J00463 北京师范大学贵阳附属中学 肖恺 
#include<bits/stdc++.h>
using namespace std;
int n;
long long e=0,cnt;
int t;
char a;
int  s[200000000000000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>t;
		cin>>a;
		for(int j=e;j<e+t;j++){
			s[j]=a;	
		}
		e+=t;
	}


	if(e%2==0){
		for(int i=e/2;i;i--){
			int w=1;
			if(s[i]!=s[i+w]){
				cnt++;
			}
			w+=2;
		}
	}
	if(e%2!=0){
		for(int i=e/2;i;i--){
			int w=2;
			if(s[i]!=s[i+w]){
				cnt++;
			}
			w+=2;
		}
	}
	cout<<cnt;

	return 0;
}
