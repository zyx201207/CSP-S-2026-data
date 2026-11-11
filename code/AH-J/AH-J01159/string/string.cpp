#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n=0;
	cin>>n;
	int i=0;
	for(int i1=1;i1<=n;i1++){
	    char a1;
	    int b;
		cin>>b;
		cin>>a1;
		for(int j=1;j<=b;j++){
			s[i]+=a1;
			i++;
		} 
    }
	int n1=0;
	int i2=i-1;
	for(int j=0;j!=(i-1)/2;j++){
		cout<<s[j]<<s[i2];
		if(s[j]==s[i2]){
			i2--;
		}
		else{
			n1++;
		}
	}
    cout<<n1<<endl;
	return 0;
}
