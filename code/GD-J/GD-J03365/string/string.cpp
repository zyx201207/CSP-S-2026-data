#include <bits/stdc++.h>
using namespace std;
int n,a,sum=0,cnt=0;
string s;
string t[100000005];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a>>s;
		for (int j=1;j<=a;j++){
			t[cnt+j]=s;
		}
		cnt+=a;
	}
	for (int i=1;i<=cnt/2;i++){
		if (t[i]!=t[cnt-i+1]){
		    sum++;
		}
    }
	cout<<sum;
	return 0;
}
