#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N];
char c[N];
string s;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long le=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		le+=a[i];
	}
	long long sum=0;
	if(le<100000000){
		s=s+'0';
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s=s+c[i];
			}
		}
		for(int i=1;i<=le/2;i++){
			if(s[i]!=s[le-i+1]){
				sum++;
			}
		}
		cout<<sum;
		return 0;
	}else{
		cout<<"0"<<endl;
	}
	
	return 0;
}