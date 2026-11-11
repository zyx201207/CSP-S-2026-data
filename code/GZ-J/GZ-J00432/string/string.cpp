//GZ-J00432 贵阳市第三十四中学 杨宗泽 
#include<bits/stdc++.h>
using namespace std;
long long n,cnt,d,s,cnt2;
char a[200005];
string z,x,y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d>>a[i];
		if(a[i]==a[i-1]){
			cnt++;
	    }
		while(d>0){
			z+=a[i];
			d--;
		}
	}
	if(cnt==n){
		cout<<0;
		return 0;
	}
	int l=z.size();
	for(int i=0;i<(l/2);i++){
		if(z[i]!=z[l-i]){
			cnt2++;
		}
		//cout<<l-i;
	}
	cout<<cnt2;
	return 0;
}
