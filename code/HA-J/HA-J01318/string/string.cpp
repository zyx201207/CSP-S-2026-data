#include<bits/stdc++.h>
using namespace std;

int n,ans;
long long a;
string s;
char c;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a>>c;
    	for(int i=1;i<=a;i++){
    		s+=c;
		}
	}
	int l=sizeof(s);
	int i=0;
	while(i<l){
		int w=l-i-1;
		if(s[i]!=s[w])ans++;
		i++;
	}
	cout<<ans;
	return 0;
}
