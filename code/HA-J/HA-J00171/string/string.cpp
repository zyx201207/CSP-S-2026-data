#include<bits/stdc++.h>
using namespace std;
char s[2000005];
int a[2000005];
long long n;
int ans[2000005];
long long l=0;
long long f=0;
long long sum=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
		l+=a[i];
	}
	if(l%2==0){
		f=l/2;
	}
	else{
		f=l/2+1;
	}
	//chushihua
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			ans[i]=(int)s[i];
		}
	}
	for(int i=0;i<f;i++){
		if(ans[i]!=ans[l-i-1]){
			sum+=1;
		}
	}
	cout<<sum;
	return 0;
	//wobuhuei
}
