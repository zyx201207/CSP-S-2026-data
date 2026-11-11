#include<bits/stdc++.h>
using namespace std;
string s;
int v[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int z=1;
	while(z<=n){
		s='0';
		for(int i=z;i<=n;i++){
		    for(int j=0;j<s.size();j++){
			    if(a[i]==s[j]){
				    for(int k=j;k<=s.size();k++){
					    s[k]='0';
				    }
			    }
		    }
		    s+=(char)(a[i]);
	    }
	    z++;
	    for(int j=0;j<s.size();j++){
	    	v[(int)(s[j])]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<v[i]<<" ";
	}
	return 0;
}
