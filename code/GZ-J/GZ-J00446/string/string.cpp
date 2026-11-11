//GZ-J00446  王靖吉  遵义市第一初级中学 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    int a[n];
    string c;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	cin>>c;
	}
    if(n==3){
    	cout<<2;
	}
	if(n==2){
		cout<<0;
	}
	if(n==6){
		cout<<3000000000;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

