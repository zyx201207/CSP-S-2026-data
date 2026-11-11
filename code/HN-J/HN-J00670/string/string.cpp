#include<bits/stdc++.h>
using namespace std;
long long n;
long long temp,temp2;
const int maxn = 1e6+5;
long long num[maxn],mp[maxn],top=0;
char str[maxn];
string fin;
int main(){
	long long ans = 0;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i = 1;i<=n;i++){
		cin>>num[i]>>str[i];
		top = top + num[i];
	}
	long long l=0,r=n;
	while(l<r){
		if(temp==0) temp = num[++l];
		if(temp2!=0){
			if(temp>=temp2){
				//cout<<l<<r<<temp<<temp2<<endl;
				if(str[l]!=str[r]) ans = ans + temp2;
				temp = temp - temp2;
				temp2 = 0;
			}
			else{
				//cout<<l<<r<<temp<<temp2<<endl;
				if(str[l]!=str[r]) ans = ans + temp;
				temp2 = temp2 - temp;
				temp = 0;
			}
		}
		if(temp>=num[r]){
			//cout<<l<<r<<temp<<temp2<<endl;
			if(str[l]!=str[r]) ans = ans + num[r];
			temp = temp - num[r--];
		}
		else{
			temp2 = num[r] - temp;
			//cout<<l<<r<<temp<<temp2<<endl;
			if(str[l]!=str[r]) ans = ans + temp;
			temp = 0;
		}
	}
	cout<<ans;
	return 0;
}
