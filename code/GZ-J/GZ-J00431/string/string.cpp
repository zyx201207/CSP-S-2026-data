//GZ-J00431 贵阳一中李端棻中学 田贺铭 
#include<bits/stdc++.h>
using namespace std;
long long n,a[10010],m;
char c[10010];
string s;
string zfc(long long x,char y){
	string s1;
	for(int i=1;i<=x;i++){
		s1+=y;
	} 
	return s1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=zfc(a[i],c[i]); 
	}
	int len = s.size();
	for(int i=0;i<=len/2;i++){
		if(s[i]!=s[len-i-1]){
			m++;
		}
	}
	cout<<m;
	return 0;
} 
