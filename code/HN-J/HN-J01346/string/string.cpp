#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],w1,w2,sum;
string c,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		w1+=a[i];
		for(int j=w2;j<=w1;j++){
			s[j]=c[0];
		}
		w2=w1;
	}
	for(int i=0;i<(w1+1)/2;i++){
		if (s[i]!=s[w1-i]){
			sum++; 
		}
	}
	cout<<sum;
	return 0;
} 
