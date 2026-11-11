#include<bits/stdc++.h>
using namespace std;
long long n,m,sum;
string a,b;
char c;
int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>m;
		cin>>c;
		for(int j=1;j<=m;j++){
			a=a+c;
	    }
	}
	int l=a.size()/2;
	for(int i=a.size()-1;i>0;i--){
		b=b+a[i];
	}
	for(int i=0;i<l;i++){
		if(a[i]!=b[i]){
			sum++;
		}
	}
	cout<<sum;
    return 0;
}
