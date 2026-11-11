#include<bits/stdc++.h>
using namespace std;
string s;
int a[2000010];
char c[2000010];
long long cnt=0;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	long long len=0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		cin >> c[i];
		len+=a[i];
	}
	int k=-1;
	for(int i=0;i<len;i+=a[k]){
		k++;
		for(int j=0;j<a[k];j++){
			s[i+j]=c[k];
			
		}
	}
	for(int i=1;i<=(len-1)/2+1;i++){
		if(s[i-1]!=s[len-i]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
