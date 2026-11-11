#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    string s;
    int n,m,f,sum,ans;
    ans=0;
    char c,c2;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>m>>c;
        for(int j=0;j<m;j++){
        	s[j]=c;
		}
    	if(i>1&&c!=c2){
    		f++;
		}
		c2=c;
		sum+=m;
	}
	if(f==1){
		cout<<0;
	}
	if(f==2){
		cout<<sum/2;
	}
	
	return 0;
}
