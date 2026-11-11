#include <bits/stdc++.h>
using namespace std;
/*struck Numchar{
	char x;
	long long num;
};*/
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	char a[n+1];
	long long b[n+1];
	string s="";
	b[0]=0;
	for (int i=1;i<=n;i++){
		cin>>b[i];
		cin>>a[i];
		for (int j=1;j<=b[i];j++){
			s+=a[i];
		}
		b[i]+=b[i-1];
	}
	int num=0;
	for (int i=0;i<(b[n]+1)/2;i++){
		if (s[i]!=s[n-i+1]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
//Ç°×ººÍ £»×Ö·û£» 
