#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
string t,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=0;j<a[i];j++){
			t[j]=c[i];
		}
	}int r=0,l=t.size(),sum=0;
	while(r<l){
		if(t[r]!=t[l]) {
			sum++;
			r++;
			l--;
		}else{
			r++;
			l--;
		}
	}cout<<sum;
}
