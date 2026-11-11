#include <bits/stdc++.h>
using namespace std;
int a[100005];
char c[100005];
char s[1000005];
char r[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	char x;
	cin>>n;
	cin>>a[1]>>c[1];
	x=c[1];
	int flag=0;
	for(int i=2;i<=n;i++){
		cin>>a[i]>>c[i];
		if(x!=c[i]){
			flag=1;
		}
	}
	if(flag==0){
		cout<<"0";
		return 0;
	}
	int sum=0;
	int w=0;
	for(int i=n;i>=1;i--){
		int h=a[i];
		for(int j=1;j<=h;j++){
			s[w]=c[i];
			w++;
		}
	}

	int k=0;
	for(int i=1;i<=n;i++){
		int h=a[i];
		for(int j=1;j<=h;j++){
			r[k]=c[i];
			k++;
		}
	}
	w=0;
	for(int i=0;i<k/2;i++){
		if(r[i]!=s[w]){
			sum++;
		}
		w++;
	}
	cout<<sum;
	return 0;
}
