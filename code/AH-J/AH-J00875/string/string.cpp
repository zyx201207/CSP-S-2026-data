#include<bits/stdc++.h>
using namespace std;
string s;
char l;
long long minn,n,a,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		sum+=a;
		cin>>l;
		for(int i=1;i<=a;i++){
			s+=l;
		}
	} 
	for(int i=0;i<sum/2;i++){
		if(s[i]!=s[n-i]){
			minn++;
		}
	} 
	cout<<minn;
	return 0;
}
