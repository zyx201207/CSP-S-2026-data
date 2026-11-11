#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char b[200010];
string s;
string back;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int size=0;
    int flag=0;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	size+=a[i];
    	cin>>b[i];
    	for(int j=1;j<=a[i];j++){
    		s+=b[i];
		}
	}
	int cnt=0;
	for(int i=0;i<size/2;i++){
		if(s[i]!=s[size-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
    return 0;
}

