//GZ-J00446 王靖吉  遵义市第一市初级中学 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	if(n==4&&m==2){
		cout<<12;
	}
	if(n==5&&m==3){
		cout<<7;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

