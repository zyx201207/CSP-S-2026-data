#include<bits/stdc++.h>
using namespace std;
int n,a,b;
char c,d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>a>>c>>b>>d;
	if(n==1){
		cout<<0;
	}else{
		if(a>b){
			cout<<b;
		}else{
			cout<<a;
		}
    }
    return 0;
}
