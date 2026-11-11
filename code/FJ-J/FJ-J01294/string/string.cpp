#include<bits/stdc++.h>
using namespace std;
long long n,ct,sum;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a[n];
	char c[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
		
	}
	if(sum%2==1){
		for(int x=sum/2,y=sum/2;x>=0,y<sum;x--,y++){
			if(s[x]==s[y]){
				ct++;
			}
			else break;
		}
		cout<<sum/2-ct+1;
	}
	else if(sum%2==0){
		for(int x=sum/2-1,y=sum/2;x>=0,y<sum;x--,y++){
				if(s[x]==s[y]){
				ct++;
			}
			else break;
		}
		cout<<sum/2-ct;
	}
	return 0;
}
