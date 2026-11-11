#include<bits/stdc++.h>
using namespace std;
char w[130000500];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a;
	char c;
	cin>>n;
	long long j=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>c;
		while(a){
			w[j]=c;
			j++;
			a--;
		}
	}
	j--;
	long long cnt=0;
	for(int i=j/2;i>=0;i--){
		if(w[j-i]!=w[i]){
			w[j-i]=w[i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}