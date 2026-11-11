#include<bits/stdc++.h>
using namespace std;
int cnt, a;
string m,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a>>c;
		for(int j=1; j<=a; j++){
			m+=c;
		}
	}
	
	for(int i=0; i<m.length()/2; i++){
		for(int j=m.length()-1; j>m.length()/2;j--){
		    if(m[i]!=m[j]){
			    m[j]=m[i];
			    cnt++;
			}else{
				continue;
			}
	    }
	}
	cout<<cnt;
	return 0;
}
