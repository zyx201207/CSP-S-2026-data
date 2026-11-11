#include<bits/stdc++.h>
using namespace std;
int n;
long long x,sum,yushu;
char c[20007];
bool flag=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c[i];
		if(x%2==0){
			sum+=x/2;
		}else{
			yushu+=x%2;
			sum+=x/2;
		}
		if(c[i]!=c[i-1]){
			flag=false;
		}
	}
	if(flag==true) cout<<0;
	else cout<<sum+yushu/2;
	return 0;
}
