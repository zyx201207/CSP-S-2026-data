#include<bits/stdc++.h>
using namespace std;
const int N=222222;
int a[N];
char c[N];
int n;
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){                                 
		cout<<min(a[1],a[2]);                            
		return 0;                                       
	}                                        
	return 0;                             
}

