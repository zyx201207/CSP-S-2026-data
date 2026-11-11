#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,num=0,n_a=0,n_b=0;
	int a[100100];
	string s[100100];
	long long nn=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=0;i<n;i++){
		nn=nn+a[i];
	}
	while(n_a!=n){
		if(s[n_a]==s[n-n_b-1]){
			num++;
		}
		
		if(a[n_a]==0&&a[n-n_b-1]>0){
			n_a++;
			a[n-n_b-1]--;
		}
		else if(a[n_a]>0&&a[n-n_b-1]==0){
			n_b++;
			a[n_a]--;
		}
		else if(a[n_a]>0&&a[n-n_b-1]>0){
			a[n_a]--;
			a[n-n_b-1]--;
		}
		else{
			n_a++;
			n_b++;
		}
	}
	cout<<(n/2)-num<<endl;
}
