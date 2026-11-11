#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
long long a[N],ym[N]; //ym --- difference 
string s;
long long cnt=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
		char c;
		cin>>a[i]>>c;
		int k=a[i];
		while(k!=0){
			s+=c;
			k--;
		}
	}
	int f=0;
	for(int i=0,j=s.size()-1;i<=j;i++,j--){
		if(s[i]!=s[j]){
			f=1;
			ym[cnt]=s[j];
			cnt++;
		}
	}
	if(f=0){
		cout<<0;
	} else {
		cout<<cnt;
	}
	return 0;
}
