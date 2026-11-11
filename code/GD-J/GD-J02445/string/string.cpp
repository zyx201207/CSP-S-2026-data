#include<bits/stdc++.h>
using namespace std;
int a[1000010];
char m[1000010];
char s[1000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>m[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		for(int j=ans;j<a[i]+ans;j++){
			s[j]=m[i];
			//cout<<s[j]<<" "<<j<<endl; 
		}
		ans+=a[i];
		//cout<<"*"<<ans<<"*";
	}
	int sun=0;
	for(int i=1;i<=(ans-1)/2;i++){
		if(s[i]!=s[ans-i])
			sun++;
	}
	cout<<sun;
	return 0;
}
/*3 
2 a
2 b
1 c
6
10000 a
10000 a
10000 a
10000 b
10000 b
10000 b
*/
