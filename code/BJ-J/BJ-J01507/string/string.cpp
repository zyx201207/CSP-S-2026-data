/*
string
n<=2*10^5
a1<=10^9

long long


*/
#include<bits/stdc++.h>
using namespace std;
int n,a[200005],qian,hou;
long long ans=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	qian=1,hou=n;
	while(qian<hou){
		if(a[qian]>a[hou]){
			if(c[qian]!=c[hou]){
				ans+=a[hou];
			}
			a[qian]-=a[hou];
			hou--;
		}else if(a[qian]==a[hou]){
			if(c[qian]!=c[hou]){
				ans+=a[hou];
			}
			qian++;
			hou--;
		}else{
			if(c[qian]!=c[hou]){
				ans+=a[qian];
			}
			a[hou]-=a[qian];
			qian++;
		}
	}
	cout<<ans;
	return 0;
}
