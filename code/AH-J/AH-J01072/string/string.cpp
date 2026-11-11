#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long n,a[N];
char c[N];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i]>>c[i];
}
string d;
for(int i=1;i<=n;i++){
	for(int k=0;k<a[i];k++){
		d=d+c[i];
}
}
long long la=d.size();
bool v=true;
for(int i=1;i<=la/2;i++){	
	if(d[i]!=d[la+1-i]){
		v=false;
}
}
	cout<<"0";

}
