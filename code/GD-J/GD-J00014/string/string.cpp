#include<bits/stdc++.h>
using namespace std;
long long a,n[100010],da,cnt,xx;
char m[1000000010],z[100010],mm[1000000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>n[i]>>z[i];
		cnt+=n[i];
		xx=cnt-n[i]+1;
		for(int j=xx;j<=cnt;j++){
			m[j]=z[i];
		}
	}
	for(int i=1;i<=a;i++){
		for(int j=cnt;j>=cnt-n[i];j--){
			mm[j]=z[i];
		}
	}
	for(int i=1;i<=a;i++){
		for(int j=cnt-n[i]+1;j<=cnt;j++){
			if(m[j]!=mm[j]){
				da++;
			}
		}
	}
	cout<<da;
}
