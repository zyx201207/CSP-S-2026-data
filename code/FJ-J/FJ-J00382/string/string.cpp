#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],q=1,cnt=0;
char b[100000005];
bool check(){
	long long r=q-1,l=1;
	while(l<r){
		if (b[l]!=b[r]){
			return false;
		}
		l++;
		r--;
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		char x;
		cin>>x;
		for (int j=1;j<=a[i];j++){
			b[q]=x;
			q++;
		}

	}
	if (check()){
		cout<<0;
	}
	else{
		long long r=q-1,l=1;
		while(l<r){
			if (b[l]!=b[r]){
				cnt++;
			}	
			l++;
			r--;
		}
		cout<<cnt;
	}
}
