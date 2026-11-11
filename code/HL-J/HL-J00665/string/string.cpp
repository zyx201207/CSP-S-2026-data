#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,a[200005],cnt=0;
char ch;
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch;
		for(int j=1;j<=a[i];j++){
			s1=s1+ch;
			s2=s2+ch;
		}
	}
	long long len=s1.size();
	for(int i=0;i<len/2;i++){
		swap(s2[i],s2[len-i-1]);
	}
	for(int i=0;i<len/2;i++){
		if(s1[i]!=s2[i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
