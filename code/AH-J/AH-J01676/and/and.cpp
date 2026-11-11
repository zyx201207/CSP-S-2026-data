
#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
for(int i=0;i<=n;i++){
	int s[i];
    cin>>s[i];
for(int i=0;i<=n;i++){
	 int a=s[i];
	 for(int y=0;y<=n;y++){
		 a&=s[i];
cout<<a;
}
}
}
return 0;
}
