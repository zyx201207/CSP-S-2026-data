#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	long long  nn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		nn+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
//	cout<<nn;
long long  ans=0;
//	if(nn%2==1){
		for(int i=0;i<nn/2;i++){	
		    if(s[i]!=s[nn-i-1]){
		    	ans++;
			}
			
		} 
		cout<<ans;
	//}
} 
/*3
2 a
2 b
1 c*/
//cout<<s[i]<<" "<<s[nn-i-1]<<'\n';
