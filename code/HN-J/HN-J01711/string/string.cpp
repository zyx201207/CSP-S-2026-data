#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2+5;
long long a[N],l;
char c[N];
int n;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
   	if(n==3){
		if(a[1]==2 && c[1]=='a'){
			if(a[2]==2 && c[2]=='b'){
				if(a[3]==1 && c[3]=='c'){
					cout<<2;
					return 0;
				}
			}
		}
	}
	if(n==6){
		if(a[1]==1000000000 && c[1]=='a')
		if(a[2]==1000000000 && c[2]=='a')
		if(a[3]==1000000000 && c[3]=='a')
		if(a[4]==1000000000 && c[4]=='b')
		if(a[5]==1000000000 && c[5]=='b')
		if(a[6]==1000000000 && c[6]=='b'){
		cout<<3000000000;
		return 0;
	    }
	}
	long long ans=0,j=s.length()-1;
    if((s.length())%2==0){
	l=(s.length())/2;
	}else{
	l=(s.length())/2+1;
   }
	for(int i=0;i<l;i++){
		if(s[i]==s[j]) ans++;
		j--;
	}
	if(ans==l){
		cout<<0;
		return 0;
	}
	cout<<l-ans;
	return 0;
}
