#include<bits/stdc++.h>
using namespace std;
const int MAX=2e5+2;
string s;
int n,sum=0;
int a[MAX];
char b[MAX];
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}	
	int l=0;
	int r=s.size();
	r--;
	while(l<r){
		if(s[l]!=s[r])sum++;
		l++;
		r--;
		}
	cout<<sum;
	return 0;
}
