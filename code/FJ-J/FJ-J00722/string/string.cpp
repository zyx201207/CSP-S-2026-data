#include<bits/stdc++.h>
using namespace std;
long long ans=0,n,j,num=0;
char a;
map<long long,char> s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>j>>a;
		for(int k=0;k<j;k++){
			s[ans]=a;
			ans++;
		}
	}
	long long i=0;
	while(i<ans-i){
		if(s[i]==s[ans-1-i]){
			i++;
			continue;
		}
		else {
			i++;
		   num++;	
		}
	}
	cout<<num;
	return 0;
}

